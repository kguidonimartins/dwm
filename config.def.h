/* See LICENSE file for copyright and license details. */

/* Constants */
#define TERMINAL "st"
#define TERMCLASS "St"

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
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
	/* class       instance      title       tags mask    isfloating   isterminal  noswallow  monitor */
	{ "Nautilus",  NULL,         NULL,       1 << 1,       0,           0,         0,         -1 },
	{ "R_x11",     NULL,         NULL,       NULL,         1,           0,         0,         -1 },
	{ "Todoist",   NULL,         NULL,       NULL,         1,           0,         0,         -1 },
	{ NULL,        "sptmux",     NULL,       SPTAG(0),     1,           1,         0,          1 },
	{ NULL,        "spterm",     NULL,       SPTAG(0),     1,           1,         0,          1 },
	{ "Brave",     NULL,         NULL,       1 << 2,       0,           0,         0,         -1 },
	{ "RStudio",   NULL,         NULL,       1 << 3,       0,           0,         0,         -1 },
	{ "Code",      NULL,         NULL,       1 << 5,       0,           0,         0,         -1 },
	{ "Zotero",    NULL,         NULL,       1 << 6,       0,           0,         0,         -1 },
	{ NULL,        "spcalc",     NULL,       SPTAG(1),     1,           1,         0,         -1 },

};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

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
#include "bindings.h"
