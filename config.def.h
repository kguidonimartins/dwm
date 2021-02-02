/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 0;        /* border pixel of windows */
static const unsigned int snap      = 10;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int swallowfloating    = 1;        /* 1 means swallow floating windows by default */
static const unsigned int systraypinning = 0;   /* 0: sloppy systray follows selected monitor, >0: pin systray to monitor X */
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int systraypinningfailfirst = 1;   /* 1: if pinning fails, display systray on the first monitor, False: display systray on the last monitor*/
static int showsystray        = 1;     /* 0 means no systray */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = {
                                        "UbuntuMono Nerd Font:size=10:antialias=true:autohint=12",
                                        "Font Awesome 5:size=8:antialias=true:autohint=true"
                                      };
static char dmenufont[]             = "UbuntuMono Nerd Font:size=8:antialias=true:autohint=8";

/* /1* DEFAULT COLORS *1/ */
/* static const char col_gray1[]       = "#222222"; */
/* static const char col_gray2[]       = "#444444"; */
/* static const char col_gray3[]       = "#bbbbbb"; */
/* static const char col_gray4[]       = "#eeeeee"; */
/* static const char col_cyan[]        = "#44475A"; */
/* static const char *colors[][3]      = { */
/*     /1*               fg         bg         border   *1/ */
/*     [SchemeNorm] = { col_gray3, col_gray1, col_gray2 }, */
/*     [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  }, */
/* }; */

/* COBALT COLORS */
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#132738";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray3, col_gray1, col_cyan },
    [SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* /1* DRACULA COLORS *1/ */
/* static const char col_gray1[]       = "#282a36"; */
/* static const char col_gray2[]       = "#ffb86c"; */
/* static const char col_gray3[]       = "#ff79c6"; */
/* static const char col_gray4[]       = "#ffb86c"; */
/* static const char col_cyan[]        = "#282a36"; */
/* static const char *colors[][3]      = { */
/*     /1*               fg         bg         border   *1/ */
/*     [SchemeNorm] = { col_gray3, col_gray1, col_cyan }, */
/*     [SchemeSel]  = { col_gray4, col_cyan,  col_gray2  }, */
/* }; */

typedef struct {
    const char *name;
    const void *cmd;
} Sp;
const char *spcmd1[] = {TERMINAL, "-n", "sptmux", "-g", "120x34", "-e", "scrax", NULL };
const char *spcmd2[] = {TERMINAL, "-n", "spcalc", "-f", "monospace:size=16", "-g", "50x20", "-e", "bc", "-lq", NULL };
const char *spcmd3[] = {TERMINAL, "-n", "spterm", "-g", "120x34", NULL };
static Sp scratchpads[] = {
	/* name          cmd  */
	{"sptmux",      spcmd1},
	{"spranger",    spcmd2},
	{"spterm",      spcmd3},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     */
    /* 1 == 1 << 8 */
    /* 2 == 1 << 1 */
    /* 3 == 1 << 2 */
    /* 4 == 1 << 3 */
    /* 5 == 1 << 4 */
    /* 6 == 1 << 5 */
    /* 7 == 1 << 6 */
    /* 8 == 1 << 7 */
    /* 9 == 1 << 0 */
	/* class         instance      title       tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Nautilus",    NULL,         NULL,       1 << 1,       0,           0,         0,         -1 },
	{ NULL,          "sptmux",     NULL,       SPTAG(0),     1,           1,         0,          1 },
	{ NULL,          "spterm",     NULL,       SPTAG(0),     1,           1,         0,          1 },
	{ "R_x11",       NULL,         NULL,       NULL,         0,           0,         0,          0 },
	{ "Brave",       NULL,         NULL,       1 << 2,       0,           0,         0,         -1 },
	{ "RStudio",     NULL,         NULL,       1 << 3,       0,           0,         0,         -1 },
	{ "Code",        NULL,         NULL,       1 << 5,       0,           0,         0,         -1 },
	{ "Zotero",      NULL,         NULL,       1 << 6,       0,           0,         0,         -1 },
	{ NULL,          "spcalc",     NULL,       SPTAG(1),     1,           1,         0,         -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int attachdirection = 2;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

#include "layouts.c"
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "HHH",      grid },
    { "DD",       doubledeck },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-l", "10", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *termcmd[]  = { "st", NULL };

/* commands spawned when clicking statusbar, the mouse button pressed is exported as BUTTON */
static char *statuscmds[] = { "notify-send Mouse$BUTTON" };
static char *statuscmd[] = { "/bin/sh", "-c", NULL, NULL };

#include <X11/XF86keysym.h>
#include "shiftview.c"

static Key keys[] = {
    /* modifier             key                 function        argument */
    { MODKEY,               XK_grave,           spawn,          SHCMD("dmenuunicode") },
    TAGKEYS(                XK_1,               0)
    TAGKEYS(                XK_2,               1)
    TAGKEYS(                XK_3,               2)
    TAGKEYS(                XK_4,               3)
    TAGKEYS(                XK_5,               4)
    TAGKEYS(                XK_6,               5)
    TAGKEYS(                XK_7,               6)
    TAGKEYS(                XK_8,               7)
    TAGKEYS(                XK_9,               8)
    { MODKEY,               XK_0,               view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,     XK_0,               tag,            {.ui = ~0 } },
    { MODKEY,               XK_minus,           spawn,          SHCMD("pulsemixer --change-volume -5; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,     XK_minus,           spawn,          SHCMD("pulsemixer --change-volume -15; kill -44 $(pidof dwmblocks)") },
    { MODKEY,               XK_equal,           spawn,          SHCMD("pulsemixer --change-volume +5; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,     XK_equal,           spawn,          SHCMD("pulsemixer --change-volume +15; kill -44 $(pidof dwmblocks)") },
    { MODKEY,               XK_BackSpace,       togglescratch,  {.ui = 0} },
    { MODKEY|ShiftMask,     XK_BackSpace,       spawn,          SHCMD("sysact") },

    { MODKEY,               XK_Tab,             view,           {0} },
    { MODKEY,               XK_q,               killclient,     {0} },
    { MODKEY|ShiftMask,     XK_q,               quit,           {0} },
    { MODKEY|ControlMask,   XK_q,               spawn,          SHCMD("kill -SEGV ""\"$(xprop | grep PID| awk '{print $3}')""\"")},
    { MODKEY,               XK_w,               spawn,          SHCMD("$BROWSER") },
    { MODKEY|ShiftMask,     XK_w,               spawn,          SHCMD(TERMINAL " -e sudo nmtui") },
    { MODKEY,               XK_e,               spawn,          SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { MODKEY|ShiftMask,     XK_e,               spawn,          SHCMD("nautilus") },
    { MODKEY,               XK_r,               spawn,          SHCMD(TERMINAL " -e lf") },
    { MODKEY|ShiftMask,     XK_r,               spawn,          SHCMD(TERMINAL " -e htop") },
    { MODKEY,               XK_t,               setlayout,      {.v = &layouts[0]} }, /* tile */
    { MODKEY|ShiftMask,     XK_t,               setlayout,      {.v = &layouts[1]} }, /* floating */
    { MODKEY,               XK_y,               setlayout,      {.v = &layouts[2]} }, /* monocle */
    { MODKEY|ShiftMask,     XK_y,               setlayout,      {.v = &layouts[3]} }, /* dwindle */
    { MODKEY,               XK_u,               setlayout,      {.v = &layouts[4]} }, /* deck */
    /* { MODKEY|ShiftMask,  XK_u,               setlayout,      {.v = &layouts[5]} }, /1* monocle *1/ */
    { MODKEY,               XK_i,               spawn,          SHCMD("dmenubookmarks") }, /* centeredmaster */
    /* { MODKEY|ShiftMask,  XK_i,               setlayout,      {.v = &layouts[7]} }, /1* centeredfloatingmaster *1/ */
    { MODKEY,               XK_o,               incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,     XK_o,               incnmaster,     {.i = -1 } },
    { MODKEY,               XK_p,               shiftview,      { .i = -1 } },
    { MODKEY|ShiftMask,     XK_p,               spawn,          SHCMD("mpc toggle && mpcnotify") },
    /* { MODKEY,               XK_bracketleft,     spawn,          SHCMD("mpc seek -10") }, */
    { MODKEY,               XK_bracketleft,     focusmaster,    {0} },
    { MODKEY|ShiftMask,     XK_bracketleft,     spawn,          SHCMD("mpc seek -60") },
    { MODKEY,               XK_bracketright,    spawn,          SHCMD("mpc seek +10") },
    { MODKEY|ShiftMask,     XK_bracketright,    spawn,          SHCMD("mpc seek +60") },
    { MODKEY,               XK_backslash,       view,           {0} },

    { MODKEY,               XK_a,               togglegaps,     {0} },
    { MODKEY|ShiftMask,     XK_a,               defaultgaps,    {0} },
    { MODKEY,               XK_s,               togglesticky,   {0} },
    // { MODKEY,               XK_d,               spawn,          {.v = dmenucmd } },
    { MODKEY,               XK_d,               spawn,          SHCMD("dmenu_recent_aliases") },
    { MODKEY,               XK_f,               togglefullscr,  {0} },
    /* { MODKEY|ShiftMask,      XK_f,               setlayout,      {.v = &layouts[8]} }, */
    { MODKEY,               XK_g,               spawn,          SHCMD("dmenuwwwquery") },
    { MODKEY|ShiftMask,     XK_g,               shifttag,       { .i = -1 } },
    { MODKEY,               XK_h,               focusmon,       {.i = -1 } },
    { MODKEY|ShiftMask,     XK_h,               tagmon,         {.i = -1 } },
    { MODKEY|ControlMask,   XK_h,               setmfact,       {.f = -0.05} },
    { MODKEY,               XK_j,               focusstack,     {.i = +1 } },
    { MODKEY,               XK_k,               focusstack,     {.i = -1 } },
    { MODKEY,               XK_l,               focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,     XK_l,               tagmon,         {.i = +1 } },
    { MODKEY|ControlMask,   XK_l,               setmfact,       {.f = +0.05} },
    /* { MODKEY,               XK_semicolon,       shiftview,      { .i = 1 } }, */
    { MODKEY|ShiftMask,     XK_semicolon,       shifttag,       { .i = 1 } },
    { MODKEY,               XK_apostrophe,      togglescratch,  {.ui = 1} },
    { MODKEY,               XK_Return,          spawn,          {.v = termcmd } },
    /* { MODKEY|ShiftMask,      XK_Return,          togglescratch,  {.ui = 0} }, */

    { MODKEY,               XK_z,               incrgaps,       {.i = +3 } },
    { MODKEY,               XK_x,               incrgaps,       {.i = -3 } },
    { MODKEY|ShiftMask,     XK_c,               spawn,          SHCMD("camtoggle") },
    { MODKEY,               XK_b,               togglebar,      {0} },
    { MODKEY,               XK_v,               spawn,          SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
    { MODKEY,               XK_n,               shiftview,      { .i = +1 } },
    { MODKEY|ShiftMask,     XK_n,               spawn,          SHCMD(TERMINAL " -e newsboat; pkill -RTMIN+6 dwmblocks") },
    { MODKEY,               XK_m,               spawn,          SHCMD(TERMINAL " -e ncmpcpp --screen playlist; kill -44 $(pidof dwmblocks)") },
    { MODKEY|ShiftMask,     XK_m,               spawn,          SHCMD("pulsemixer --toggle-mute; kill -44 $(pidof dwmblocks)") },
    { MODKEY,               XK_comma,           spawn,          SHCMD("mpc prev") },
    { MODKEY|ShiftMask,     XK_comma,           spawn,          SHCMD("mpc seek 0%") },
    { MODKEY,               XK_period,          spawn,          SHCMD("mpc next") },
    { MODKEY|ShiftMask,     XK_period,          spawn,          SHCMD("mpc repeat") },

    { MODKEY,               XK_Left,            focusmon,       {.i = -1 } },
    { MODKEY|ShiftMask,     XK_Left,            tagmon,         {.i = -1 } },
    { MODKEY,               XK_Right,           focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,     XK_Right,           tagmon,         {.i = +1 } },

    /* { MODKEY,               XK_Page_Up,         shiftview,      { .i = -1 } }, */
    { MODKEY|ShiftMask,     XK_Page_Up,         shifttag,       { .i = -1 } },
    /* { MODKEY,               XK_Page_Down,       shiftview,      { .i = +1 } }, */
    { MODKEY|ShiftMask,     XK_Page_Down,       shifttag,       { .i = +1 } },
    { MODKEY,               XK_Insert,          spawn,          SHCMD("xdotool type $(cat ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },

    { MODKEY,               XK_F1,              spawn,          SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
    { MODKEY,               XK_F2,              spawn,          SHCMD("tutorialvids") },
    { MODKEY,               XK_F3,              spawn,          SHCMD("displayselect") },
    { MODKEY,               XK_F4,              spawn,          SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
    /* { MODKEY,                XK_F5,              xrdb,           {.v = NULL } }, */
    { MODKEY,               XK_F6,              togglesystray,  {0} },
    { MODKEY,               XK_F7,              spawn,          SHCMD("td-toggle") },
    { MODKEY,               XK_F8,              spawn,          SHCMD("mailsync; kill -44 $(pidof dwmblocks)") },
    { MODKEY,               XK_F9,              spawn,          SHCMD("dmenumount") },
    { MODKEY,               XK_F10,             spawn,          SHCMD("dmenuumount") },
    { MODKEY,               XK_F11,             spawn,          SHCMD("camtoggle") },
    /* { MODKEY,                XK_F12,             xrdb,           {.v = NULL } }, */
    { 0,                    XK_F12,             togglescratch,  {.ui = 0} },
    { MODKEY,               XK_space,           zoom,           {0} },
    { MODKEY|ShiftMask,     XK_space,           togglefloating, {0} },

    { 0,                    XK_Print,           spawn,          SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
    { ShiftMask,            XK_Print,           spawn,          SHCMD("maimpick") },
    { MODKEY,               XK_Print,           spawn,          SHCMD("dmenurecord") },
    { MODKEY|ShiftMask,     XK_Print,           spawn,          SHCMD("dmenurecord kill") },
    { MODKEY,               XK_Delete,          spawn,          SHCMD("dmenurecord kill") },
    { MODKEY,               XK_Scroll_Lock,     spawn,          SHCMD("killall screenkey || screenkey &") },

    { 0, XF86XK_AudioMute,                      spawn,          SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioRaiseVolume,               spawn,          SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioLowerVolume,               spawn,          SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioPrev,                      spawn,          SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Previous") },
    { 0, XF86XK_AudioNext,                      spawn,          SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Next") },
    { 0, XF86XK_AudioPause,                     spawn,          SHCMD("mpc pause") },
    { 0, XF86XK_AudioPlay,                      spawn,          SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.PlayPause") },
    { 0, XF86XK_AudioStop,                      spawn,          SHCMD("dbus-send --print-reply --dest=org.mpris.MediaPlayer2.spotify /org/mpris/MediaPlayer2 org.mpris.MediaPlayer2.Player.Stop") },
    { 0, XF86XK_AudioRewind,                    spawn,          SHCMD("mpc seek -10") },
    { 0, XF86XK_AudioForward,                   spawn,          SHCMD("mpc seek +10") },
    { 0, XF86XK_AudioMedia,                     spawn,          SHCMD(TERMINAL " -e ncmpcpp") },
    { 0, XF86XK_AudioMicMute,                   spawn,          SHCMD("pactl set-source-mute @DEFAULT_SOURCE@ toggle") },
    { 0, XF86XK_PowerOff,                       spawn,          SHCMD("sysact") },
    { 0, XF86XK_Calculator,                     spawn,          SHCMD(TERMINAL " -e bc -l") },
    { 0, XF86XK_Sleep,                          spawn,          SHCMD("sudo -A zzz") },
    { 0, XF86XK_WWW,                            spawn,          SHCMD("$BROWSER") },
    { 0, XF86XK_DOS,                            spawn,          SHCMD(TERMINAL) },
    { 0, XF86XK_ScreenSaver,                    spawn,          SHCMD("slock & xset dpms force off; mpc pause; pauseallmpv") },
    { 0, XF86XK_TaskPane,                       spawn,          SHCMD(TERMINAL " -e htop") },
    { 0, XF86XK_Mail,                           spawn,          SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { 0, XF86XK_MyComputer,                     spawn,          SHCMD(TERMINAL " -e lf /") },
    { 0, XF86XK_Launch1,                        spawn,          SHCMD("xset dpms force off") },
    { 0, XF86XK_TouchpadToggle,                 spawn,          SHCMD("(synclient | grep 'TouchpadOff.*1' && synclient TouchpadOff=0) || synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOff,                    spawn,          SHCMD("synclient TouchpadOff=1") },
    { 0, XF86XK_TouchpadOn,                     spawn,          SHCMD("synclient TouchpadOff=0") },
    { 0, XF86XK_MonBrightnessUp,                spawn,          SHCMD("xbacklight -inc 15") },
    { 0, XF86XK_MonBrightnessDown,              spawn,          SHCMD("xbacklight -dec 15") },

    /* { MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } }, */
    /* { MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } }, */
    /* { MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } }, */
    /* { MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } }, */
    /* { MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} }, */
    /* { MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } }, */
    /* { MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } }, */
    /* { MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } }, */
    /* { MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } }, */
    /* { MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } }, */
    /* { MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } }, */
    /* { MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } }, */
    /* { MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } }, */

};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button1,        sigdwmblocks,   {.i = 1} },
    { ClkStatusText,        0,              Button2,        sigdwmblocks,   {.i = 2} },
    { ClkStatusText,        0,              Button3,        sigdwmblocks,   {.i = 3} },
    { ClkStatusText,        0,              Button4,        sigdwmblocks,   {.i = 4} },
    { ClkStatusText,        0,              Button5,        sigdwmblocks,   {.i = 5} },
    { ClkStatusText,        ShiftMask,      Button1,        sigdwmblocks,   {.i = 6} },
    { ClkStatusText,        ShiftMask,      Button3,        spawn,          SHCMD(TERMINAL " -e nvim ~/.local/suckless/dwmblocks/config.h") },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button1,        resizemouse,    {0} },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

