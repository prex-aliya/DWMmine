<h1 align="center" style="font-size:72px">DWMmine - my suckless window manager</h1>

__Now without Status Bar__

![DWM](./.img/dwm.png)

This is my every day use case, dwm customization.
Mine comes with out a status bar, because I have the most
suckless status bar off all, a clock.


# BSD

This was made for bsd, so it has a special config.mk and Makefile, if you want
to use on linux, all you have to do is:

> git clone git://git.suckless.org/dwm

in a seperate directory and copy the Makefile from there and remove the
config.mk. Then all you have to do is build normally


# Uniqueness

- Three levels of 9 workspaces
    * For used when both hands are on keyboard
- No status bar
    * For the most suckless thing, a clock.
- Cropwindows
    * Mod-Shift-Space to revert back
    * Mod-Shift-RigtMouse to move in crop
    * Mod-Shift-LeftMouse to crop at cursor
- Fake fullscreen
    * fullscreening a video stays within its window
    * Only allow clients to "fullscreen" into space currently given to them.


# Working On / Desired Additions

- Move mouse with monitor to corner instead of middle
- custom patch for multiple layers of tags
- completly rewrite it, from the ground up (different branch).
- patches
    * aspectresize
    * goback
    * xtile
    * stacker
    * multikey
    * freespace
    * exresize
    * defaultlayooutpermonitor
    * keypressrelease
    * current_desktop
    * cool_autostart
    * reorganizetags
    * ~~fakefullscreen~~
    * ~~cropwindows~~
    * ~~cursorwarp~~
    * ~~doublepressquit~~
    * ~~keychain~~
    * ~~sticky~~
- ~~remove status bar.~~
- ~~use with my keyboard layout.~~
