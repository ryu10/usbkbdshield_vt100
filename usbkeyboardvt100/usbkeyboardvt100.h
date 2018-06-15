/*
 * usbkeyboardvt100.h
 */

const byte vt100_key_tbl[] = {
    0x00, // #00 OPEN
    0x03, // #01 <delete>
    0x04, // #02 Alt <return>
    0x05, // #03 p
    0x06, // #04 o
    0x07, // #05 y
    0x08, // #06 t
    0x09, // #07 w
    0x0A, // #08 q
    0x10, // #09 <rightArrow>
    0x14, // #10 ]
    0x15, // #11 [
    0x16, // #12 I
    0x17, // #13 u
    0x18, // #14 r
    0x19, // #15 e
    0x1A, // #16 1
    0x20, // #17 <leftArrow>
    0x22, // #18 <downArrow>
    0x23, // #19 <break>
    0x24, // #20  `
    0x25, // #21  -
    0x26, // #22 9
    0x27, // #23 7
    0x28, // #24 4
    0x29, // #25 3
    0x2A, // #26 <esc>
    0x30, // #27 <upArrow>
    0x31, // #28 PF3
    0x32, // #29 PF1
    0x33, // #30 <backspace>
    0x34, // #31 +
    0x35, // #32 0
    0x36, // #33 8
    0x37, // #34 6
    0x38, // #35 5
    0x39, // #36 2
    0x3A, // #37 <tab>
    0x40, // #38 <num>7
    0x41, // #39 PF4
    0x42, // #40 PF2
    0x43, // #41 <num>0
    0x44, // #42 | <bar>
    0x45, // #43 <line feed>
    0x46, // #44 l
    0x47, // #45 k
    0x48, // #46 g
    0x49, // #47 f
    0x4A, // #48 a
    0x50, // #49 <num>8
    0x51, // #50 <num><Enter>
    0x52, // #51 <num>2
    0x53, // #52 <num>1
    0x55, // #53 "
    0x56, // #54 ;
    0x57, // #55 j
    0x58, // #56 h
    0x59, // #57 d
    0x5A, // #58 s
    0x60, // #59 <num> .
    0x61, // #60 <num> .
    0x62, // #61 <num>5
    0x63, // #62 <num>4
    0x64, // #63 <return>
    0x65, // #64 >
    0x66, // #65 <
    0x67, // #66 n
    0x68, // #67 b
    0x69, // #68 x
    0x6A, // #69 <no scroll>
    0x70, // #70 <num>9
    0x71, // #71 <num>3
    0x72, // #72 <num>6
    0x73, // #73 <num> -
    0x75, // #74 ?
    0x76, // #75 m
    0x77, // #76 <space>
    0x78, // #77 v
    0x79, // #78 c
    0x7A, // #79 z
    0x7B, // #80 <setup>
    0x7C, // #81 <ctrl>
    0x7D, // #82 <shift>
    0x7E, // #83 <caps lock>
    0x7F  // #84 CLOSED <scan end>
  };

#define VT100KEYS 85 // sizeof(vt100_key_tbl)

int vt100_key_status[VT100KEYS];

const int usb_key_tbl[] = {
 0, // : vt100_key_tbl index | USB: #000 0x00 Reserved (no event indicated)    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #001 0x01 Keyboard ErrorRollOver           | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #002 0x02 Keyboard POSTFail                | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #003 0x03 Keyboard ErrorUndefined          | VT100: 0x00  UNUSED
48, // : vt100_key_tbl index | USB: #004 0x04 Keyboard a and A                 | VT100: 0x4A  a
67, // : vt100_key_tbl index | USB: #005 0x05 Keyboard b and B                 | VT100: 0x68  b
78, // : vt100_key_tbl index | USB: #006 0x06 Keyboard c and C                 | VT100: 0x79  c
57, // : vt100_key_tbl index | USB: #007 0x07 Keyboard d and D                 | VT100: 0x59  d
15, // : vt100_key_tbl index | USB: #008 0x08 Keyboard e and E                 | VT100: 0x19  e
47, // : vt100_key_tbl index | USB: #009 0x09 Keyboard f and F                 | VT100: 0x49  f
46, // : vt100_key_tbl index | USB: #010 0x0A Keyboard g and G                 | VT100: 0x48  g
56, // : vt100_key_tbl index | USB: #011 0x0B Keyboard h and H                 | VT100: 0x58  h
12, // : vt100_key_tbl index | USB: #012 0x0C Keyboard i and I                 | VT100: 0x16  i
55, // : vt100_key_tbl index | USB: #013 0x0D Keyboard j and J                 | VT100: 0x57  j
45, // : vt100_key_tbl index | USB: #014 0x0E Keyboard k and K                 | VT100: 0x47  k
44, // : vt100_key_tbl index | USB: #015 0x0F Keyboard l and L                 | VT100: 0x46  l
75, // : vt100_key_tbl index | USB: #016 0x10 Keyboard m and M                 | VT100: 0x76  m
66, // : vt100_key_tbl index | USB: #017 0x11 Keyboard n and N                 | VT100: 0x67  n
 4, // : vt100_key_tbl index | USB: #018 0x12 Keyboard o and O                 | VT100: 0x06  o
 3, // : vt100_key_tbl index | USB: #019 0x13 Keyboard p and P                 | VT100: 0x05  p
 8, // : vt100_key_tbl index | USB: #020 0x14 Keyboard q and Q                 | VT100: 0x0A  q
14, // : vt100_key_tbl index | USB: #021 0x15 Keyboard r and R                 | VT100: 0x18  r
58, // : vt100_key_tbl index | USB: #022 0x16 Keyboard s and S                 | VT100: 0x5A  s
 6, // : vt100_key_tbl index | USB: #023 0x17 Keyboard t and T                 | VT100: 0x08  t
13, // : vt100_key_tbl index | USB: #024 0x18 Keyboard u and U                 | VT100: 0x17  u
77, // : vt100_key_tbl index | USB: #025 0x19 Keyboard v and V                 | VT100: 0x78  v
 7, // : vt100_key_tbl index | USB: #026 0x1A Keyboard w and W                 | VT100: 0x09  w
68, // : vt100_key_tbl index | USB: #027 0x1B Keyboard x and X                 | VT100: 0x69  x
 5, // : vt100_key_tbl index | USB: #028 0x1C Keyboard y and Y                 | VT100: 0x07  y
79, // : vt100_key_tbl index | USB: #029 0x1D Keyboard z and Z                 | VT100: 0x7A  z
16, // : vt100_key_tbl index | USB: #030 0x1E Keyboard 1 and !                 | VT100: 0x1A  1
36, // : vt100_key_tbl index | USB: #031 0x1F Keyboard 2 and @                 | VT100: 0x39  2
25, // : vt100_key_tbl index | USB: #032 0x20 Keyboard 3 and #                 | VT100: 0x29  3
24, // : vt100_key_tbl index | USB: #033 0x21 Keyboard 4 and $                 | VT100: 0x28  4
35, // : vt100_key_tbl index | USB: #034 0x22 Keyboard 5 and %                 | VT100: 0x38  5
34, // : vt100_key_tbl index | USB: #035 0x23 Keyboard 6 and ^                 | VT100: 0x37  6
23, // : vt100_key_tbl index | USB: #036 0x24 Keyboard 7 and &                 | VT100: 0x27  7
33, // : vt100_key_tbl index | USB: #037 0x25 Keyboard 8 and *                 | VT100: 0x36  8
22, // : vt100_key_tbl index | USB: #038 0x26 Keyboard 9 and (                 | VT100: 0x26  9
32, // : vt100_key_tbl index | USB: #039 0x27 Keyboard 0 and )                 | VT100: 0x35  0
63, // : vt100_key_tbl index | USB: #040 0x28 Keyboard Return (ENTER)          | VT100: 0x04  <return>
26, // : vt100_key_tbl index | USB: #041 0x29 Keyboard ESCAPE                  | VT100: 0x2A  <esc>
30, // : vt100_key_tbl index | USB: #042 0x2A Keyboard DELETE (Backspace)      | VT100: 0x33  <backspace>
37, // : vt100_key_tbl index | USB: #043 0x2B Keyboard Tab                     | VT100: 0x3A  <tab>
76, // : vt100_key_tbl index | USB: #044 0x2C Keyboard Spacebar                | VT100: 0x77  <space>
21, // : vt100_key_tbl index | USB: #045 0x2D Keyboard - and (underscore)      | VT100: 0x25   -_
31, // : vt100_key_tbl index | USB: #046 0x2E Keyboard = and +                 | VT100: 0x34  =+
11, // : vt100_key_tbl index | USB: #047 0x2F Keyboard [ and {                 | VT100: 0x15  [{
10, // : vt100_key_tbl index | USB: #048 0x30 Keyboard ] and }                 | VT100: 0x14  ]}
#ifdef SWAPLFBAR
42, // : vt100_key_tbl index | USB: #049 0x31 Keyboard \ and |                 | VT100: 0x44  \|
#else
43, // : vt100_key_tbl index | USB: #049 0x31 Keyboard \ and |                 | VT100: 0x45  \|
#endif // SWAPLFBAR
 0, // : vt100_key_tbl index | USB: #050 0x32 Keyboard Non-US # and ~          | VT100: 0x00  UNUSED
54, // : vt100_key_tbl index | USB: #051 0x33 Keyboard ; and :                 | VT100: 0x56  ;:
53, // : vt100_key_tbl index | USB: #052 0x34 Keyboard ' and "                 | VT100: 0x55  '"
20, // : vt100_key_tbl index | USB: #053 0x35 Keyboard Grave Accent and Tilde  | VT100: 0x24   `~
65, // : vt100_key_tbl index | USB: #054 0x36 Keyboard, and <                  | VT100: 0x66  ,<
64, // : vt100_key_tbl index | USB: #055 0x37 Keyboard . and >                 | VT100: 0x65  .>
74, // : vt100_key_tbl index | USB: #056 0x38 Keyboard / and ?                 | VT100: 0x75  /?
#ifdef SWAPCAPS
81, // : vt100_key_tbl index | USB: #057 0x39 Keyboard Caps Lock               | VT100: 0x7C  <ctrl>
#else // SWAPCAPS undefined
83, // : vt100_key_tbl index | USB: #057 0x39 Keyboard Caps Lock               | VT100: 0x7E  <caps lock>
#endif // SWAPCAPS
80, // : vt100_key_tbl index | USB: #058 0x3A Keyboard F1                      | VT100: 0x7B  <setup>
 0, // : vt100_key_tbl index | USB: #059 0x3B Keyboard F2                      | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #060 0x3C Keyboard F3                      | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #061 0x3D Keyboard F4                      | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #062 0x3E Keyboard F5                      | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #063 0x3F Keyboard F6                      | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #064 0x40 Keyboard F7                      | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #065 0x41 Keyboard F8                      | VT100: 0x00  UNUSED
29, // : vt100_key_tbl index | USB: #066 0x42 Keyboard F9                      | VT100: 0x32  PF1
40, // : vt100_key_tbl index | USB: #067 0x43 Keyboard F10                     | VT100: 0x42  PF2
28, // : vt100_key_tbl index | USB: #068 0x44 Keyboard F11                     | VT100: 0x31  PF3
39, // : vt100_key_tbl index | USB: #069 0x45 Keyboard F12                     | VT100: 0x41  PF4
80, // : vt100_key_tbl index | USB: #070 0x46 Keyboard PrintScreen and SysRq   | VT100: 0x7B  <setup>
69, // : vt100_key_tbl index | USB: #071 0x47 Keyboard Scroll Lock             | VT100: 0x6A  <no scroll>
19, // : vt100_key_tbl index | USB: #072 0x48 Keyboard Pause                   | VT100: 0x23  <break>
 0, // : vt100_key_tbl index | USB: #073 0x49 Keyboard Insert                  | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #074 0x4A Keyboard Home                    | VT100: 0x00  UNUSED
39, // : vt100_key_tbl index | USB: #075 0x4B Keyboard PageUp                  | VT100: 0x41  PF4 layout based but irregular
 1, // : vt100_key_tbl index | USB: #076 0x4C Keyboard Delete Forward          | VT100: 0x03  <delete>
#ifdef SWAPLFBAR
43, // : vt100_key_tbl index | USB: #077 0x4D Keyboard End                     | VT100: 0x45  <line feed> layout based
#else
42, // : vt100_key_tbl index | USB: #077 0x4D Keyboard End                     | VT100: 0x44  <line feed> layout based
#endif // SWAPLFBAR
 0, // : vt100_key_tbl index | USB: #078 0x4E Keyboard PageDown                | VT100: 0x00  UNUSED
 9, // : vt100_key_tbl index | USB: #079 0x4F Keyboard RightArrow              | VT100: 0x10  <right_arrow>
17, // : vt100_key_tbl index | USB: #080 0x50 Keyboard LeftArrow               | VT100: 0x20  <left_arrow>
18, // : vt100_key_tbl index | USB: #081 0x51 Keyboard DownArrow               | VT100: 0x22  <down_arrow>
27, // : vt100_key_tbl index | USB: #082 0x52 Keyboard UpArrow                 | VT100: 0x30  <up_arrow>
29, // : vt100_key_tbl index | USB: #083 0x53 Keypad Num Lock and Clear        | VT100: 0x32  PF1 layout based
40, // : vt100_key_tbl index | USB: #084 0x54 Keypad /                         | VT100: 0x42  PF2 layout based
28, // : vt100_key_tbl index | USB: #085 0x55 Keypad *                         | VT100: 0x31  PF3 layout based
73, // : vt100_key_tbl index | USB: #086 0x56 Keypad -                         | VT100: 0x73  <pad> -
60, // : vt100_key_tbl index | USB: #087 0x57 Keypad +                         | VT100: 0x61  <pad> , Layout based
50, // : vt100_key_tbl index | USB: #088 0x58 Keypad ENTER                     | VT100: 0x51  <pad><Enter>
52, // : vt100_key_tbl index | USB: #089 0x59 Keypad 1 and End                 | VT100: 0x53  <pad>1
51, // : vt100_key_tbl index | USB: #090 0x5A Keypad 2 and Down Arrow          | VT100: 0x52  <pad>2
71, // : vt100_key_tbl index | USB: #091 0x5B Keypad 3 and PageDn              | VT100: 0x71  <pad>3
62, // : vt100_key_tbl index | USB: #092 0x5C Keypad 4 and Left Arrow          | VT100: 0x63  <pad>4
61, // : vt100_key_tbl index | USB: #093 0x5D Keypad 5                         | VT100: 0x62  <pad>5
72, // : vt100_key_tbl index | USB: #094 0x5E Keypad 6 and Right Arrow         | VT100: 0x72  <pad>6
38, // : vt100_key_tbl index | USB: #095 0x5F Keypad 7 and Home                | VT100: 0x40  <pad>7
49, // : vt100_key_tbl index | USB: #096 0x60 Keypad 8 and Up Arrow            | VT100: 0x50  <pad>8
70, // : vt100_key_tbl index | USB: #097 0x61 Keypad 9 and PageUp              | VT100: 0x70  <pad>9
41, // : vt100_key_tbl index | USB: #098 0x62 Keypad 0 and Insert              | VT100: 0x43  <pad>0
59, // : vt100_key_tbl index | USB: #099 0x63 Keypad . and Delete              | VT100: 0x60  <pad> .
42, // : vt100_key_tbl index | USB: #100 0x64 Keyboard Non-US \ and |          | VT100: 0x45  \|
 2, // : vt100_key_tbl index | USB: #101 0x65 Keyboard Application (Win menu)  | VT100: 0x64  <return> alt
80, // : vt100_key_tbl index | USB: #102 0x66 Keyboard Power                   | VT100: 0x7B  <setup> function based
31, // : vt100_key_tbl index | USB: #103 0x67 Keypad =                         | VT100: 0x34  =+
80, // : vt100_key_tbl index | USB: #104 0x68 Keyboard F13                     | VT100: 0x7B  <setup> for Mac 104
69, // : vt100_key_tbl index | USB: #105 0x69 Keyboard F14                     | VT100: 0x6A  <no scroll> for Mac 104
19, // : vt100_key_tbl index | USB: #106 0x6A Keyboard F15                     | VT100: 0x23  <break> for Mac 104
 0, // : vt100_key_tbl index | USB: #107 0x6B Keyboard F16                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #108 0x6C Keyboard F17                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #109 0x6D Keyboard F18                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #110 0x6E Keyboard F19                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #111 0x6F Keyboard F20                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #112 0x70 Keyboard F21                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #113 0x71 Keyboard F22                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #114 0x72 Keyboard F23                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #115 0x73 Keyboard F24                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #116 0x74 Keyboard Execute                 | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #117 0x75 Keyboard Help                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #118 0x76 Keyboard Menu                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #119 0x77 Keyboard Select                  | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #120 0x78 Keyboard Stop                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #121 0x79 Keyboard Again                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #122 0x7A Keyboard Undo                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #123 0x7B Keyboard Cut                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #124 0x7C Keyboard Copy                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #125 0x7D Keyboard Paste                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #126 0x7E Keyboard Find                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #127 0x7F Keyboard Mute                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #128 0x80 Keyboard Volume Up               | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #129 0x81 Keyboard Volume Down             | VT100: 0x00  UNUSED
83, // : vt100_key_tbl index | USB: #130 0x82 Keyboard Locking Caps Lock       | VT100: 0x7E  <caps lock> vt100's locking capslock
 0, // : vt100_key_tbl index | USB: #131 0x83 Keyboard Locking Num Lock        | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #132 0x84 Keyboard Locking Scroll Lock     | VT100: 0x00  UNUSED
60, // : vt100_key_tbl index | USB: #133 0x85 Keypad Comma                     | VT100: 0x61  <pad> , function based
31, // : vt100_key_tbl index | USB: #134 0x86 Keypad Equal Sign                | VT100: 0x34  =+
 0, // : vt100_key_tbl index | USB: #135 0x87 Keyboard International1          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #136 0x88 Keyboard International2          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #137 0x89 Keyboard International3          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #138 0x8A Keyboard International4          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #139 0x8B Keyboard International5          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #140 0x8C Keyboard International6          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #141 0x8D Keyboard International7          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #142 0x8E Keyboard International8          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #143 0x8F Keyboard International9          | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #144 0x90 Keyboard LANG1                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #145 0x91 Keyboard LANG2                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #146 0x92 Keyboard LANG3                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #147 0x93 Keyboard LANG4                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #148 0x94 Keyboard LANG5                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #149 0x95 Keyboard LANG6                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #150 0x96 Keyboard LANG7                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #151 0x97 Keyboard LANG8                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #152 0x98 Keyboard LANG9                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #153 0x99 Keyboard Alternate Erase         | VT100: 0x00  UNUSED
80, // : vt100_key_tbl index | USB: #154 0x9A Keyboard SysReq/Attention        | VT100: 0x7B  <setup> functional based
 0, // : vt100_key_tbl index | USB: #155 0x9B Keyboard Cancel                  | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #156 0x9C Keyboard Clear                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #157 0x9D Keyboard Prior                   | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #158 0x9E Keyboard Return                  | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #159 0x9F Keyboard Separator               | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #160 0xA0 Keyboard Out                     | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #161 0xA1 Keyboard Oper                    | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #162 0xA2 Keyboard Clear/Again             | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #163 0xA3 Keyboard CrSel/Props             | VT100: 0x00  UNUSED
 0, // : vt100_key_tbl index | USB: #164 0xA4 Keyboard ExSel                   | VT100: 0x00  UNUSED
// USB: #165 - #255, 91 unused
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,   0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
   0
};

// Mapping for the modifier keys

#define VT100SHIFT 82 // vt100 Shift index in vt100_key_tbl[]
#define VT100CTRL 81  // vt100 Ctrl index in vt100_key_tbl[]
#define VT100CAPSLOCK 83  // vt100 Caps lock index in vt100_key_tbl[]
// #define VT100ALT   // ALT not used in vt100
// #define VT100GUI   // GUI not used in vt100
