/* See LICENSE file for copyright and license details. */

/* appearance ---------------------------------------------- {{{ */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";

/* https://lospec.com/palette-list/cyberpunk-neons */
/*                Darker > Lighter              */
static const char col_pink1[]   =  "#0b001b";
static const char col_pink2[]   =  "#4d004f";
static const char col_pink3[]   =  "#c1115a";
static const char col_pink4[]   =  "#e13a6a";

static const char col_blue1[]   =  "#03274c";
static const char col_blue2[]   =  "#03274c";
static const char col_blue3[]   =  "#0f9595";
static const char col_blue4[]   =  "#53ebe4";

static const char col_red[]     = "#ff0546";
static const char col_blue[]     = "#0ce6f2";

static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_blue, col_blue, col_blue },
	[SchemeSel]  = { col_red, col_red, col_red },
};
/* appearance }}} */

/* tagging -------------------------------------------------{{{ */
// TODO: Remove need for names V
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12",
    "13", "14", "15", "16" };
static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* class            instance    title       tags mask       isfloating      monitor */
    { "Gimp",           NULL,       NULL,       0,              1,              -1 },
};
/* tagging -------------------------------------------------}}} */

/* layout(s) -----------------------------------------------{{{ */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = { // TODO: remove symbol
	/* symbol     arrange function */
        //{ "|+|",      tatami },
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	//{ "[M]",      monocle }, // TODO: Remove this layout
};
/* layout(s) -----------------------------------------------}}} */

/* Key Definitions ----------------------------------------- {{{ */
#define MODKEY Mod4Mask
#define AltKey Mod1Mask
#define TAGKEYS(CHAIN, KEY,TAG) \
    { MODKEY,                       CHAIN,      KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           CHAIN,      KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             CHAIN,      KEY,      tag,            {.ui = 1 << TAG} },
    //{ MODKEY|ControlMask|ShiftMask, CHAIN,      KEY,      toggletag,      {.ui = 1 << TAG} }, // No need for this

/* Commands */

static const char *dmenucmd[] = { "dmenu_run", NULL };
//static const char *dmenucmd2[] = { "rofi -show run", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *mouse[]  = { "xmouseless", NULL };
static const char *screenlock[]  = { "slock", NULL };

static const Key keys[] = {
    /* modifier                     chain               key             function            argument */
    { MODKEY,                       -1,                 XK_p,           spawn,              {.v = dmenucmd } },
    { MODKEY|ShiftMask,             -1,                 XK_Return,      spawn,              {.v = termcmd } },
    { MODKEY,                       -1,                 XK_o,           spawn,              {.v = mouse}},
    { MODKEY,                       -1,                 XK_c,           spawn,              {.v = screenlock} },


    { MODKEY,                       -1,                 XK_j,           setmfact,           {.f = -0.01} },
    { MODKEY,                       -1,                 XK_k,           setmfact,           {.f = +0.01} },
    { MODKEY,                       -1,                 XK_l,           focusstack,         {.i = +1 } },
    { MODKEY,                       -1,                 XK_h,           focusstack,         {.i = -1 } },

    { MODKEY,                       -1,                 XK_Return,      zoom,               {0} },
    { MODKEY,                       -1,                 XK_Tab,         view,               {0} },
    { MODKEY,                       -1,                 XK_q,           killclient,         {0} },
    { MODKEY|ShiftMask,             -1,                 XK_space,       togglefloating,     {0} },
    { MODKEY,                       -1,                 XK_s,           togglesticky,       {0} },

    { MODKEY,                       -1,                 XK_0,           view,               {.ui = ~0 } },
    { MODKEY|ShiftMask,             -1,                 XK_0,           tag,                {.ui = ~0 } },

    { MODKEY|ShiftMask,             -1,                 XK_h,           focusmon,           {.i = +1 } },
    { MODKEY|ShiftMask,             -1,                 XK_l,           focusmon,           {.i = -1 } },
    { MODKEY|ShiftMask,             -1,                 XK_g,           tagmon,             {.i = -1 } },
    { MODKEY,                       -1,                 XK_g,           tagmon,             {.i = +1 } },

    TAGKEYS(                        -1,                 XK_1,                               0)
    TAGKEYS(                        -1,                 XK_2,                               1)
    TAGKEYS(                        -1,                 XK_3,                               2)
    TAGKEYS(                        -1,                 XK_4,                               3)
    TAGKEYS(                        -1,                 XK_5,                               4)
    TAGKEYS(                        -1,                 XK_6,                               5)
    TAGKEYS(                        -1,                 XK_7,                               6)
    TAGKEYS(                        -1,                 XK_8,                               7)
    TAGKEYS(                        -1,                 XK_9,                               8)

    { MODKEY,                       XK_b,               XK_b,           view,               {.ui = 1 << 9} },
    TAGKEYS(                        XK_b,               XK_1,                               10)
    TAGKEYS(                        XK_b,               XK_2,                               11)
    TAGKEYS(                        XK_b,               XK_3,                               12)

    { MODKEY,                       XK_m,               XK_m,           view,               {.ui = 1 << 13} },
    TAGKEYS(                        XK_m,               XK_1,                               14)
    TAGKEYS(                        XK_m,               XK_2,                               15)


    { MODKEY|AltKey,                XK_q,                 XK_q,           quit,               {0} }, /* EXIT */

    //{ MODKEY|ShiftMask,             -1,                 XK_p,           spawn,              {.v = dmenucmd2 } },
    { MODKEY|ControlMask,           -1,                 XK_g,           incnmaster,         {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask, -1,                 XK_g,           incnmaster,         {.i = -1 } },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                        event mask          button          function        argument */
    { ClkLtSymbol,                  0,                  Button1,        setlayout,          {0} },
    { ClkLtSymbol,                  0,                  Button3,        setlayout,          {.v = &layouts[2]} },
    { ClkWinTitle,                  0,                  Button2,        zoom,               {0} },
    { ClkStatusText,                0,                  Button2,        spawn,              {.v = termcmd } },
    { ClkClientWin,                 MODKEY,             Button1,        movemouse,          {0} },
    { ClkClientWin,                 MODKEY|ShiftMask,   Button1,        movemouse,          {.i = 1} }, /* cropwindows */
    { ClkClientWin,                 MODKEY,             Button2,        togglefloating,     {0} },
    { ClkClientWin,                 MODKEY,             Button3,        resizemouse,        {0} },
    { ClkClientWin,                 MODKEY|ShiftMask,   Button3,        resizemouse,        {.i = 1} }, /* cropwindows */
    { ClkTagBar,                    0,                  Button1,        view,               {0} },
    { ClkTagBar,                    0,                  Button3,        toggleview,         {0} },
    { ClkTagBar,                    MODKEY,             Button1,        tag,                {0} },
    { ClkTagBar,                    MODKEY,             Button3,        toggletag,          {0} },
};
/* key definitions }}} */
