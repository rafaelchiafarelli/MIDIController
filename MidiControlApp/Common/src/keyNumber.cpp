#include <keyNumber.hpp>
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
unsigned int KeySet::lhash ( const char *str,  size_t len)
{
  static unsigned short asso_values[] =
    {
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 103, 173,
      206,  63,  52, 131,  81, 226,  29,   9, 156, 993,
      993, 993, 993, 993, 993,  68, 129, 132, 196, 128,
       14, 215, 152, 239, 993,  44, 993, 137, 192, 179,
       13,   6, 164,  79, 198, 152,  30, 993, 993, 156,
      993, 200, 993, 993, 993, 993, 252, 170, 121, 193,
      199,  83, 150, 182, 194, 160,  93, 115, 100,   7,
      240,  51, 152, 192, 155, 138, 253, 147, 198,  15,
      125,  77, 249,  77, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993, 993, 993, 993,
      993, 993, 993, 993, 993, 993, 993
    };
   unsigned int hval = len;
  switch (hval)
    {
      default:
        hval += asso_values[(unsigned char)str[2]+1];
      /*FALLTHROUGH*/
      case 2:
        hval += asso_values[(unsigned char)str[1]+1];
      /*FALLTHROUGH*/
      case 1:
        hval += asso_values[(unsigned char)str[0]];
        break;
    }
  return hval + asso_values[(unsigned char)str[len - 1]];
}


namedKeyCodes KeySet::oneKeySet( const char *str,  size_t len)
{
      namedKeyCodes ret = {.name = NULL, .number = 0};
  enum
    {
      TOTAL_KEYWORDS = 232,
      MIN_WORD_LENGTH = 2,
      MAX_WORD_LENGTH = 16,
      MIN_HASH_VALUE = 190,
      MAX_HASH_VALUE = 992
    };
  static namedKeyCodes wordlist[] =
    {
      {"f8",65},
      {"kOne",89},
      {"f3",60},
      {"kPlus",87},
      {"lang9",152},
      {"minus",45},
      {"kPipe",201},
      {"lang8",151},
      {"f9",66},
      {"kExponential",195},
      {"lang4",147},
      {"f23",114},
      {"f4",61},
      {"undo",122},
      {"lang3",146},
      {"kEnter",88},
      {"lang6",149},
      {"menu",118},
      {"f5",62},
      {"kPercentage",196},
      {"inter9",143},
      {"kDzero",176},
      {"Tilde",50},
      {"lArrow",80},
      {"inter8",142},
      {"kEqual0",103},
      {"f18",109},
      {"Clear0",156},
      {"f24",115},
      {"execute",116},
      {"kTzero",177},
      {"Prior",157},
      {"kClearEntry",217},
      {"f7",64},
      {"lang5",148},
      {"Cancel",155},
      {"letter_m",16},
      {"kDoubleECom",200},
      {"altErase",153},
      {"inter4",138},
      {"end",77},
      {"letter_w",26},
      {"f2",59},
      {"kBinary",218},
      {"inter3",137},
      {"singleCuotes",52},
      {"kOctal",219},
      {"uArrow",82},
      {"kECommertial",199},
      {"mute",127},
      {"enter",40},
      {"deleteKey",42},
      {"rArrow",79},
      {"inter6",140},
      {"kTwo",90},
      {"lang1",144},
      {"kXOR",194},
      {"letter_o",18},
      {"kExclamation",207},
      {"f6",63},
      {"kBackspace",187},
      {"kEqual1",134},
      {"Clear1",162},
      {"kCloseBrakets",185},
      {"kOpenBrakets",184},
      {"kCloseParentesis",183},
      {"kOpenParentesis",182},
      {"f13",104},
      {"kNine",97},
      {"kClear",216},
      {"kDeleteKey",76},
      {"kEight",96},
      {"letter_y",28},
      {"lang2",145},
      {"f22",113},
      {"dArrow",81},
      {"letter_e",8},
      {"kDoublePipe",202},
      {"f20",111},
      {"lAlt",226},
      {"inter5",139},
      {"find",126},
      {"letter_j",13},
      {"kDecimal",220},
      {"lang7",150},
      {"letter_l",15},
      {"help",117},
      {"ExSel",164},
      {"kFive",93},
      {"kTab",186},
      {"vol_up",128},
      {"kThree",91},
      {"letter_k",14},
      {"kZero",98},
      {"kHexF",193},
      {"f19",110},
      {"lGUI",227},
      {"letter_b",5},
      {"letter_x",27},
      {"f1",58},
      {"kSix",94},
      {"inter1",135},
      {"kTwoDots",203},
      {"space",44},
      {"equal",46},
      {"f14",105},
      {"letter_s",22},
      {"kMinus",86},
      {"kLess",197},
      {"kMemMultiply",213},
      {"kMode",198},
      {"rAlt",230},
      {"kMemStore",208},
      {"kMemDivide",214},
      {"letter_u",24},
      {"Currency",180},
      {"select",119},
      {"letter_f",9},
      {"lControl",224},
      {"letter_p",19},
      {"pause",72},
      {"letter_r",21},
      {"lock_num_l",131},
      {"lock_caps_l",130},
      {"lock_scroll_l",132},
      {"letter_i",12},
      {"kMemRecall",209},
      {"Kat",206},
      {"inter2",136},
      {"f15",106},
      {"kBackSlash",100},
      {"CrSel",163},
      {"letter_a",4},
      {"reserved9",170},
      {"kHexA",188},
      {"rGUI",231},
      {"oBracket",47},
      {"kChangeSignal",215},
      {"Separator",159},
      {"letter_g",10},
      {"power",102},
      {"inter7",141},
      {"kMultiply",85},
      {"stop",120},
      {"kSpace",205},
      {"f21",112},
      {"reserved8",169},
      {"letter_q",20},
      {"letter_c",6},
      {"letter_h",11},
      {"scrollLock",71},
      {"letter_v",25},
      {"letter_d",7},
      {"vol_down",129},
      {"rControl",228},
      {"f17",108},
      {"copy",124},
      {"reserved4",165},
      {"reserved14",175},
      {"kMemClear",210},
      {"escape",41},
      {"pageUp",75},
      {"n_zero",39},
      {"f12",69},
      {"capslock",57},
      {"reserved3",3},
      {"reserved13",174},
      {"n_nine",38},
      {"printScreen",70},
      {"f10",67},
      {"kHexE",192},
      {"kHexB",189},
      {"kComma",133},
      {"kHexC",190},
      {"kFour",92},
      {"backSlash",49},
      {"letter_n",17},
      {"forwardSlash",56},
      {"reserved6",167},
      {"reserved16",223},
      {"kDot",99},
      {"letter_z",29},
      {"letter_t",23},
      {"kMemAdd",211},
      {"kHashTag",204},
      {"f16",107},
      {"reserved0",0},
      {"reserved10",171},
      {"home",74},
      {"twoDots",51},
      {"kHexa",221},
      {"Oper",161},
      {"kForwardSlash",84},
      {"tab",43},
      {"n_two",31},
      {"reserved5",166},
      {"reserved15",222},
      {"kHexD",191},
      {"decSep",179},
      {"Return",158},
      {"kSeven",95},
      {"pageDown",78},
      {"lShift",225},
      {"kMemSubtract",212},
      {"insert",73},
      {"cBracket",48},
      {"n_three",32},
      {"again",121},
      {"n_one",30},
      {"CurrencySubUnit",181},
      {"f11",68},
      {"reserved1",1},
      {"reserved11",172},
      {"dot",55},
      {"comma",54},
      {"n_five",34},
      {"thSep",178},
      {"rShift",229},
      {"reserved2",2},
      {"reserved12",173},
      {"SysReq",154},
      {"Out",160},
      {"past",125},
      {"reserved7",168},
      {"cut",123},
      {"numLock",83},
      {"application",101},
      {"acuteAcent",53},
      {"n_four",33},
      {"n_six",35},
      {"n_eight",37},
      {"n_seven",36}
    };
  static short lookup[] =
    {
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
        0,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,   1,   2,  -1,  -1,
       -1,   3,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,   4,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,   5,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,   6,  -1,  -1,  -1,   7,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,   8,   9,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  10,
       -1,  11,  -1,  -1,  -1,  12,  13,  -1,  -1,  -1,
       14,  15,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  16,  17,
       -1,  -1,  -1,  -1,  18,  19,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  20,  -1,  -1,  -1,  21,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  22,  -1,  23,  -1,
       -1,  -1,  -1,  24,  25,  -1,  -1,  26,  27,  28,
       29,  30,  -1,  -1,  31,  -1,  32,  33,  34,  -1,
       35,  -1,  36,  37,  -1,  38,  39,  -1,  -1,  40,
       41,  42,  -1,  -1,  43,  -1,  -1,  44,  -1,  -1,
       -1,  -1,  45,  46,  -1,  47,  -1,  48,  -1,  49,
       -1,  50,  51,  52,  -1,  53,  -1,  54,  -1,  -1,
       55,  -1,  56,  -1,  -1,  -1,  57,  -1,  58,  59,
       -1,  60,  -1,  -1,  61,  -1,  -1,  -1,  62,  63,
       64,  -1,  65,  66,  67,  68,  -1,  -1,  -1,  69,
       70,  71,  72,  73,  -1,  74,  -1,  75,  76,  77,
       -1,  -1,  78,  79,  -1,  80,  -1,  81,  82,  -1,
       -1,  83,  -1,  84,  -1,  85,  -1,  86,  87,  -1,
       -1,  88,  -1,  89,  -1,  90,  91,  -1,  -1,  -1,
       92,  93,  -1,  94,  95,  96,  97,  -1,  -1,  -1,
       98,  99,  -1,  -1,  -1, 100,  -1, 101, 102, 103,
       -1, 104, 105, 106, 107, 108, 109, 110, 111, 112,
      113,  -1, 114, 115, 116, 117, 118, 119,  -1, 120,
      121, 122, 123,  -1, 124, 125,  -1, 126, 127,  -1,
      128, 129, 130, 131,  -1, 132, 133, 134,  -1,  -1,
      135,  -1, 136,  -1, 137, 138,  -1, 139,  -1, 140,
      141, 142,  -1, 143, 144, 145, 146, 147, 148, 149,
      150,  -1,  -1, 151, 152, 153,  -1,  -1,  -1,  -1,
       -1, 154,  -1,  -1, 155,  -1,  -1,  -1, 156, 157,
      158, 159,  -1,  -1, 160, 161, 162,  -1, 163, 164,
      165, 166, 167,  -1, 168, 169,  -1, 170, 171, 172,
       -1, 173, 174,  -1, 175, 176, 177,  -1, 178, 179,
       -1,  -1, 180,  -1, 181,  -1,  -1,  -1, 182,  -1,
       -1,  -1,  -1, 183,  -1, 184, 185,  -1,  -1,  -1,
      186, 187,  -1, 188,  -1, 189,  -1,  -1,  -1, 190,
      191,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1, 192,
       -1, 193,  -1,  -1,  -1, 194,  -1,  -1, 195, 196,
       -1,  -1,  -1,  -1,  -1, 197, 198, 199,  -1, 200,
       -1,  -1,  -1,  -1,  -1, 201,  -1, 202,  -1,  -1,
       -1,  -1, 203, 204, 205,  -1,  -1,  -1,  -1, 206,
      207,  -1, 208,  -1,  -1,  -1, 209,  -1, 210,  -1,
      211, 212,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1, 213,  -1,  -1,  -1,  -1,  -1,
      214,  -1,  -1, 215,  -1,  -1,  -1,  -1, 216,  -1,
       -1,  -1, 217, 218, 219,  -1,  -1,  -1,  -1, 220,
      221,  -1,  -1, 222,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1, 223, 224,  -1,  -1,  -1,  -1,  -1,
      225,  -1,  -1,  -1,  -1, 226,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
      227,  -1,  -1,  -1,  -1, 228,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1, 229,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 230,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,  -1,
       -1,  -1, 231
    };

  if (len <= MAX_WORD_LENGTH && len >= MIN_WORD_LENGTH)
    {
       unsigned int key = lhash (str, len);

      if (key <= MAX_HASH_VALUE)
        {
          int index = lookup[key];

          if (index >= 0)
            {
               const char *s = wordlist[index].name;

              if (*str == *s && !strcmp (str + 1, s + 1)){
                  ret = wordlist[index];
              }
                
            }
        }
    }
  return ret;
}
