#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define the number of devices we have in the chain and the hardware interface
// NOTE: These pin numbers will probably not work with your hardware and may
// need to be adapted
#define HARDWARE_TYPE MD_MAX72XX::PAROLA_HW
#define MAX_DEVICES 8
#define CLK_PIN   13
#define DATA_PIN  11
#define CS_PIN    10

// Hardware SPI connection
MD_Parola P = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);
// Arbitrary output pins
// MD_Parola P = MD_Parola(HARDWARE_TYPE, DATA_PIN, CLK_PIN, CS_PIN, MAX_DEVICES);

// Global data
struct sCatalog
{
  textEffect_t  effect;   // text effect to display
  const char *  psz;      // text string nul terminated
  uint16_t      speed;    // speed multiplier of library default
  uint16_t      pause;    // pause multiplier for library default
};

sCatalog catalog[] =
{
  { PA_PRINT, "ELECTRONICA", 1, 1 },
  { PA_SLICE, "     IPN", 1, 1 },
  { PA_MESH, "BIENVENIDOS", 20, 1 },
  { PA_FADE, "  MATRIZ LED ", 20, 1 },
  { PA_OPENING, "ELECTRONICA", 3, 1 },
  { PA_OPENING_CURSOR, "   ROBOTICA", 4, 1 },
  { PA_SCROLL_LEFT, "CLUB MINI-ROBOTICA", 5, 1 },
  { PA_SCROLL_RIGHT, "CLUB MINI-ROBOTICA", 5, 1 },  
  { PA_CLOSING, "  ARDUINO", 3, 1 },
  { PA_CLOSING_CURSOR, "    ARDUINO", 4, 1 },
  { PA_BLINDS, "  IPN", 7, 1 },
  { PA_DISSOLVE, "   PANTALLA", 7, 1 },
  { PA_SCROLL_UP, "   INTELIGENCIA ARTIFICAL", 5, 1 },
  { PA_SCROLL_DOWN, "  CIRCUITOS", 5, 1 },
  { PA_SCROLL_LEFT, "IA", 5, 1 },
  { PA_SCAN_HORIZ, "    IA", 4, 1 },
  { PA_SCAN_VERT, " INTELIGENCIA ARTIFICAL", 3, 1 },  
  { PA_SCROLL_UP_RIGHT, "  UPIIT", 7, 1 },
  { PA_SCROLL_DOWN_RIGHT, "  UPIIT", 7, 1 },
  { PA_SCROLL_UP, "    IPN", 5, 1 },
  { PA_SCROLL_DOWN, "   IPN", 5, 1 },
  { PA_SCROLL_LEFT, "IPN", 5, 1 },
  { PA_SCROLL_RIGHT, "IPN", 5, 1 },
};

// Sprite Definitions
const uint8_t F_PMAN1 = 6;
const uint8_t W_PMAN1 = 8;
static const uint8_t PROGMEM pacman1[F_PMAN1 * W_PMAN1] =  // gobbling pacman animation
{
  0x00, 0x81, 0xc3, 0xe7, 0xff, 0x7e, 0x7e, 0x3c,
  0x00, 0x42, 0xe7, 0xe7, 0xff, 0xff, 0x7e, 0x3c,
  0x24, 0x66, 0xe7, 0xff, 0xff, 0xff, 0x7e, 0x3c,
  0x3c, 0x7e, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c,
  0x24, 0x66, 0xe7, 0xff, 0xff, 0xff, 0x7e, 0x3c,
  0x00, 0x42, 0xe7, 0xe7, 0xff, 0xff, 0x7e, 0x3c,
};

const uint8_t F_PMAN2 = 6;
const uint8_t W_PMAN2 = 18;
static const uint8_t PROGMEM pacman2[F_PMAN2 * W_PMAN2] =  // ghost pursued by a pacman
{
  0x00, 0x81, 0xc3, 0xe7, 0xff, 0x7e, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0xfe, 0x7b, 0xf3, 0x7f, 0xfb, 0x73, 0xfe,
  0x00, 0x42, 0xe7, 0xe7, 0xff, 0xff, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0xfe, 0x7b, 0xf3, 0x7f, 0xfb, 0x73, 0xfe,
  0x24, 0x66, 0xe7, 0xff, 0xff, 0xff, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0xfe, 0x7b, 0xf3, 0x7f, 0xfb, 0x73, 0xfe,
  0x3c, 0x7e, 0xff, 0xff, 0xff, 0xff, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0xfe, 0x73, 0xfb, 0x7f, 0xf3, 0x7b, 0xfe,
  0x24, 0x66, 0xe7, 0xff, 0xff, 0xff, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0xfe, 0x73, 0xfb, 0x7f, 0xf3, 0x7b, 0xfe,
  0x00, 0x42, 0xe7, 0xe7, 0xff, 0xff, 0x7e, 0x3c, 0x00, 0x00, 0x00, 0xfe, 0x73, 0xfb, 0x7f, 0xf3, 0x7b, 0xfe,
};

void setup(void)
{
  P.begin();
  for (uint8_t i=0; i<ARRAY_SIZE(catalog); i++)
  {
    catalog[i].speed *= P.getSpeed();
    catalog[i].pause *= 300;
  }
}

void loop(void)
{
  static textPosition_t just = PA_LEFT;
  static uint8_t i = 0;   // text effect index
  static uint8_t j = 0;   // text justification index

  if (P.displayAnimate()) // animates and returns true when an animation is completed
  {
    // rotate the justification if needed
    if (i == ARRAY_SIZE(catalog))
    {
      j++;
      if (j == 3) j = 0;

      switch (j)
      {
      case 0: just = PA_LEFT;    break;
      case 1: just = PA_CENTER;  break;
      case 2: just = PA_RIGHT;   break;
      }

      i = 0;  // reset loop index
    }

    // set up new animation
    P.displayText(catalog[i].psz, just, catalog[i].speed, catalog[i].pause, catalog[i].effect, catalog[i].effect);

    i++;   // then set up for next text effect
  }
}