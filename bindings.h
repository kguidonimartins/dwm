
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
    { MODKEY,               XK_w,               spawn,          SHCMD("$BROWSER") },
    { MODKEY|ShiftMask,     XK_w,               spawn,          SHCMD(TERMINAL " -e sudo nmtui") },
    { MODKEY,               XK_e,               spawn,          SHCMD(TERMINAL " -e neomutt ; pkill -RTMIN+12 dwmblocks") },
    { MODKEY|ShiftMask,     XK_e,               spawn,          SHCMD("sysact") },
    { MODKEY,               XK_r,               spawn,          SHCMD(TERMINAL " -e lf") },
    { MODKEY|ShiftMask,     XK_r,               spawn,          SHCMD(TERMINAL " -e htop") },
    { MODKEY,               XK_t,               setlayout,      {.v = &layouts[0]} }, /* tile */
    { MODKEY|ShiftMask,     XK_t,               setlayout,      {.v = &layouts[1]} }, /* floating */
    { MODKEY,               XK_y,               setlayout,      {.v = &layouts[2]} }, /* monocle */
    { MODKEY|ShiftMask,     XK_y,               setlayout,      {.v = &layouts[3]} }, /* dwindle */
    { MODKEY,               XK_u,               setlayout,      {.v = &layouts[4]} }, /* deck */
    /* { MODKEY|ShiftMask,  XK_u,               setlayout,      {.v = &layouts[5]} }, /1* monocle *1/ */
    /* { MODKEY,            XK_i,               setlayout,      {.v = &layouts[6]} }, /1* centeredmaster *1/ */
    /* { MODKEY|ShiftMask,  XK_i,               setlayout,      {.v = &layouts[7]} }, /1* centeredfloatingmaster *1/ */
    { MODKEY,               XK_o,               incnmaster,     {.i = +1 } },
    { MODKEY|ShiftMask,     XK_o,               incnmaster,     {.i = -1 } },
    { MODKEY,               XK_p,               shiftview,      { .i = -1 } },
    { MODKEY|ShiftMask,     XK_p,               spawn,          SHCMD("mpc toggle ; mpcnotify") },
    { MODKEY,               XK_bracketleft,     spawn,          SHCMD("mpc seek -10") },
    { MODKEY|ShiftMask,     XK_bracketleft,     spawn,          SHCMD("mpc seek -60") },
    { MODKEY,               XK_bracketright,    spawn,          SHCMD("mpc seek +10") },
    { MODKEY|ShiftMask,     XK_bracketright,    spawn,          SHCMD("mpc seek +60") },
    { MODKEY,               XK_backslash,       view,           {0} },

    { MODKEY,               XK_a,               togglegaps,     {0} },
    { MODKEY|ShiftMask,     XK_a,               defaultgaps,    {0} },
    /* { MODKEY,                XK_s,               togglesticky,   {0} }, */
    { MODKEY,               XK_d,               spawn,          {.v = dmenucmd } },
    { MODKEY,               XK_f,               togglefullscr,  {0} },
    /* { MODKEY|ShiftMask,      XK_f,               setlayout,      {.v = &layouts[8]} }, */
    { MODKEY,               XK_g,               shiftview,      { .i = -1 } },
    { MODKEY|ShiftMask,     XK_g,               shifttag,       { .i = -1 } },
    { MODKEY,               XK_h,               focusmon,       {.i = -1 } },
    { MODKEY|ShiftMask,     XK_h,               tagmon,         {.i = -1 } },
    { MODKEY|ControlMask,   XK_h,               setmfact,       {.f = -0.05} },
    { MODKEY,               XK_j,               focusstack,     {.i = +1 } },
    { MODKEY,               XK_k,               focusstack,     {.i = -1 } },
    { MODKEY,               XK_l,               focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,     XK_l,               tagmon,         {.i = +1 } },
    { MODKEY|ControlMask,   XK_l,               setmfact,       {.f = +0.05} },
    { MODKEY,               XK_semicolon,       shiftview,      { .i = 1 } },
    { MODKEY|ShiftMask,     XK_semicolon,       shifttag,       { .i = 1 } },
    /* { MODKEY,                XK_apostrophe,      togglescratch,  {.ui = 1} }, */
    { MODKEY,               XK_Return,          spawn,          {.v = termcmd } },
    /* { MODKEY|ShiftMask,      XK_Return,          togglescratch,  {.ui = 0} }, */

    /* { MODKEY,            XK_z,               incrgaps,       {.i = +3 } }, */
    /* { MODKEY,            XK_x,               incrgaps,       {.i = -3 } }, */
    { MODKEY,               XK_b,               togglebar,      {0} },
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

    { MODKEY,               XK_Page_Up,         shiftview,      { .i = -1 } },
    { MODKEY|ShiftMask,     XK_Page_Up,         shifttag,       { .i = -1 } },
    { MODKEY,               XK_Page_Down,       shiftview,      { .i = +1 } },
    { MODKEY|ShiftMask,     XK_Page_Down,       shifttag,       { .i = +1 } },
    { MODKEY,               XK_Insert,          spawn,          SHCMD("xdotool type $(cat ~/.local/share/larbs/snippets | dmenu -i -l 50 | cut -d' ' -f1)") },

    { MODKEY,               XK_F1,              spawn,          SHCMD("groff -mom /usr/local/share/dwm/larbs.mom -Tpdf | zathura -") },
    { MODKEY,               XK_F2,              spawn,          SHCMD("tutorialvids") },
    { MODKEY,               XK_F3,              spawn,          SHCMD("displayselect") },
    { MODKEY,               XK_F4,              spawn,          SHCMD(TERMINAL " -e pulsemixer; kill -44 $(pidof dwmblocks)") },
    /* { MODKEY,                XK_F5,              xrdb,           {.v = NULL } }, */
    { MODKEY,               XK_F6,              togglesystray,  {0} },
    { MODKEY,               XK_F7,              spawn,          SHCMD("td-toggle") },
    { MODKEY,               XK_F8,              spawn,          SHCMD("mw -Y") },
    { MODKEY,               XK_F9,              spawn,          SHCMD("dmenumount") },
    { MODKEY,               XK_F10,             spawn,          SHCMD("dmenuumount") },
    { MODKEY,               XK_F11,             spawn,          SHCMD("mpv --no-cache --no-osc --no-input-default-bindings --input-conf=/dev/null --title=webcam $(ls /dev/video[0,2,4,6,8] | tail -n 1)") },
    /* { MODKEY,                XK_F12,             xrdb,           {.v = NULL } }, */
    { 0,                    XK_F12,             togglescratch,  {.ui = 0} },
    { MODKEY,               XK_space,           zoom,           {0} },
    /* { MODKEY|ShiftMask,  XK_space,           togglefloating, {0} }, */

    { 0,                    XK_Print,           spawn,          SHCMD("maim pic-full-$(date '+%y%m%d-%H%M-%S').png") },
    { ShiftMask,            XK_Print,           spawn,          SHCMD("maimpick") },
    { MODKEY,               XK_Print,           spawn,          SHCMD("dmenurecord") },
    { MODKEY|ShiftMask,     XK_Print,           spawn,          SHCMD("dmenurecord kill") },
    { MODKEY,               XK_Delete,          spawn,          SHCMD("dmenurecord kill") },
    { MODKEY,               XK_Scroll_Lock,     spawn,          SHCMD("killall screenkey || screenkey &") },

    { 0, XF86XK_AudioMute,                      spawn,          SHCMD("pamixer -t; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioRaiseVolume,               spawn,          SHCMD("pamixer --allow-boost -i 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioLowerVolume,               spawn,          SHCMD("pamixer --allow-boost -d 3; kill -44 $(pidof dwmblocks)") },
    { 0, XF86XK_AudioPrev,                      spawn,          SHCMD("mpc prev") },
    { 0, XF86XK_AudioNext,                      spawn,          SHCMD("mpc next") },
    { 0, XF86XK_AudioPause,                     spawn,          SHCMD("mpc pause") },
    { 0, XF86XK_AudioPlay,                      spawn,          SHCMD("mpc play") },
    { 0, XF86XK_AudioStop,                      spawn,          SHCMD("mpc stop") },
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

