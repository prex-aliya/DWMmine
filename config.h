/* See LICENSE file for copyright and license details. */

/* appearance ---------------------------------------------- {{{ */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#005577";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};
/* appearance }}} */

/* tagging -------------------------------------------------{{{ */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12",
    "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27" };
static char lockfile[] = "/tmp/dwm.lock"; /* Lockfile */
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
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};
/* layout(s) -----------------------------------------------}}} */

/* key definitions ----------------------------------------- {{{ */
#define MODKEY Mod4Mask
#define AltKey Mod1Mask
#define TAGKEYS(CHAIN, KEY,TAG) \
    { MODKEY,                       CHAIN,      KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           CHAIN,      KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             CHAIN,      KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, CHAIN,      KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion
 * #define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
 */

/* commands */
static const char *dmenucmd[] = { "dmenu_run", NULL };
static const char *termcmd[]  = { "/usr/local/bin/st", NULL };
static const char *mouse[]  = { "xmouseless", NULL };
static const char *screenlock[]  = { "slock", NULL };

static const Key keys[] = {
    /* modifier                     chain               key             function            argument */
    { MODKEY,                       -1,                 XK_p,           spawn,              {.v = dmenucmd } },
    { MODKEY|ShiftMask,             -1,                 XK_Return,      spawn,              {.v = termcmd } },
    { MODKEY,                       -1,                 XK_o,           spawn,              {.v = mouse}},
    { MODKEY,                       -1,                 XK_c,           spawn,              {.v = screenlock} },

    { MODKEY|ControlMask,           -1,                 XK_g,           incnmaster,         {.i = +1 } },
    { MODKEY|ControlMask|ShiftMask, -1,                 XK_g,           incnmaster,         {.i = -1 } },
    { MODKEY,                       -1,                 XK_h,           setmfact,           {.f = -0.05} },
    { MODKEY,                       -1,                 XK_l,           setmfact,           {.f = +0.05} },

    { MODKEY,                       -1,                 XK_Return,      zoom,               {0} },
    { MODKEY,                       -1,                 XK_Tab,         view,               {0} },
    { MODKEY,                       -1,                 XK_q,           killclient,         {0} },
    { MODKEY|ShiftMask,             -1,                 XK_space,       togglefloating,     {0} },
    { MODKEY,                       -1,                 XK_s,           togglesticky,       {0}},

    { MODKEY,                       -1,                 XK_0,           view,               {.ui = ~0 } },
    { MODKEY|ShiftMask,             -1,                 XK_0,           tag,                {.ui = ~0 } },

    { MODKEY,                       -1,                 XK_j,           focusstack,         {.i = +1 } },
    { MODKEY,                       -1,                 XK_k,           focusstack,         {.i = -1 } },
    { MODKEY|ShiftMask,             -1,                 XK_j,           focusmon,           {.i = +1 } },
    { MODKEY|ShiftMask,             -1,                 XK_k,           focusmon,           {.i = -1 } },
    { MODKEY|ShiftMask,             -1,                 XK_g,           tagmon,             {.i = -1 } },
    { MODKEY,                       -1,                 XK_g,           tagmon,             {.i = +1 } },

    /* TAGKEYS(                        -1,                 XK_ampersand,                       0) */

    TAGKEYS(                        -1,                 XK_1,                               0)
    TAGKEYS(                        -1,                 XK_2,                               1)
    TAGKEYS(                        -1,                 XK_3,                               2)
    TAGKEYS(                        -1,                 XK_4,                               3)
    TAGKEYS(                        -1,                 XK_5,                               4)
    TAGKEYS(                        -1,                 XK_6,                               5)
    TAGKEYS(                        -1,                 XK_7,                               6)
    TAGKEYS(                        -1,                 XK_8,                               7)
    TAGKEYS(                        -1,                 XK_9,                               8)
    TAGKEYS(                        XK_b,               XK_b,                               9)
    TAGKEYS(                        XK_b,               XK_1,                               9)
    TAGKEYS(                        XK_b,               XK_2,                               10)
    TAGKEYS(                        XK_b,               XK_3,                               11)
    TAGKEYS(                        XK_b,               XK_4,                               12)
    TAGKEYS(                        XK_b,               XK_5,                               13)
    TAGKEYS(                        XK_b,               XK_6,                               14)
    TAGKEYS(                        XK_b,               XK_7,                               15)
    TAGKEYS(                        XK_b,               XK_8,                               16)
    TAGKEYS(                        XK_b,               XK_9,                               17)
    TAGKEYS(                        XK_m,               XK_m,                               18)
    TAGKEYS(                        XK_m,               XK_1,                               18)
    TAGKEYS(                        XK_m,               XK_2,                               19)
    TAGKEYS(                        XK_m,               XK_3,                               20)
    TAGKEYS(                        XK_m,               XK_4,                               21)
    TAGKEYS(                        XK_m,               XK_5,                               22)
    TAGKEYS(                        XK_m,               XK_6,                               23)
    TAGKEYS(                        XK_m,               XK_7,                               24)
    TAGKEYS(                        XK_m,               XK_8,                               25)
    TAGKEYS(                        XK_m,               XK_9,                               26)
    { MODKEY|AltKey,                -1,                 XK_q,           quit,               {0} }, /* EXIT */
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
