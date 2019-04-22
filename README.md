This repository contains the [QMK firmware](https://github.com/qmk/qmk_firmware) keymaps used with my OLKB Planck and Preonic programmable ortholinear keyboards (keys are aligned vertically and horizontally as opposed to staggered like typical keyboards).  There is nothing particularly clever or special about the keymaps and since most of my computer time is spent within MacOS and Spacemacs there are features specific to each. 

![Lo-pro Planck with MT3 /dev/tty keycaps photo](/planck.jpeg)

### Features

- use row number macros R1(...) to R5(...) to conditionally compile for both keyboards with the same keymap cleanly
- adopts Jack's embedded style repository with QMK pinned as a submodule*
- heavy use of home row modifiers to minimize pinky use
- layer invoked CMD+TAB with cycling in the MacOS app switcher and single tap previous app toggle
- navigation helpers for Evil (an extensible VI layer for Emacs emulating the main features of VIM) on the navigation layer
- uses sensible mnemonics where possible
- provides a guest layer giving a WYSIWYG keymap via ADJUST [G]uest.

&ast; not currently an issue as all required features are present and appear working but the paradigm breaks with more recent QMK commits due to Makefile changes.

### Layers

#### Base layer (Qwerty)
```
                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
                │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
       Tap ( -- │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │ -- Tap )
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
       Tap [ -- │ GUI │Hyper│  ⌥  │  ⌘  │  ↓  │Space│ Nav │  ↑  │  ⌘  │  ⌥  │Hyper│ GUI │ -- Tap ]
                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
                        /             Tap Backspace __/                       /
       Tap ] [ --------'-----------------------------------------------------'
```

#### Base layer (Guest)
```
                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
                │  `  │  1  │  2  │  3  │  4  │  5  │  6  │  7  │  8  │  9  │  0  │  -  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │  ⇥  │  Q  │  W  │  E  │  R  │  T  │  Y  │  U  │  I  │  O  │  P  │  '  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │  ⌃  │  A  │  S  │  D  │  F  │  G  │  H  │  J  │  K  │  L  │  ;  │  ⌃  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │  ⇧  │  Z  │  X  │  C  │  V  │  B  │  N  │  M  │  ,  │  .  │  /  │  ⇧  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │ Fn  │Ctrl │  ⌥  │  ⌘  │  ↓  │Space│Bkspc│  ↑  │  ←  │  ↓  │  ↑  │  →  │
                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
```

#### Numeric layer
```
                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
                │     │     │     │     │     │     │     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │  +  │  7  │  8  │  9  │  =  │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │  -  │  4  │  5  │  6  │  *  │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │     │  1  │  2  │  3  │  /  │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │ Del │  0  │  ,  │  .  │     │     │
                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
```

#### Symbol layer
```
                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
                │     │     │     │     │     │     │     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │  ~  │     │  &  │  *  │  {  │  }  │  `  │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │  ~/ │  _  │  $  │  %  │  ^  │  |  │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │  #  │     │  !  │  @  │  £  │  \  │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │     │     │  ,  │  .  │     │     │
                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
```

#### Navigation layer
```
                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
                │     │     │     │     │     │     │     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │App/s│     │     │ C-e │     │     │ C-y │ C-u │ C-i │ C-o │     │App/t│
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │App/t│ C-a │     │ C-d │ C-f │     │  ←  │  ↓  │  ↑  │  →  │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │ G-x │ G-c │ G-v │ C-b │     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │     │     │     │     │     │     │
                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
```

#### Adjust layer
```
                ┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
                │     │     │     │     │     │     │     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │Qwert│Make │     │Reset│Tmux │     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │Sleep│Spotl│     │     │     │Guest│     │     │     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │Vers │     │     │Music│     │     │     │     │
                ├─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┼─────┤
                │     │     │     │     │     │     │     │     │     │     │     │     │
                └─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┴─────┘
```
