[Modern Terminal User Interfaces in Python](https://www.youtube.com/watch?v=RJ-ZFzaEvzM&t=145s) 

## Terminal

### clearing the screen

```python
#Clear the whole screen.
print(term.clear())

#Clear to the end of the line.
print(term.clear_eol())

#Clear backward to the beginning of the line.
print(term.clear_bol())

#Clear to the end of screen.
print(term.clear_eos())
```

### Hyperlinks

```python
print(f"blessed {term.link('https://blessed.readthedocs.org', 'documentation')}")
```

### Window title

```python
print(term.set_window_title('My Application'))

# use with context manager
with term.window_title('Working...'):
    do_long_task()
# previous title is restored
```

### Progress Bar

> display a graphic progress indicator in terminal's _taskbar_ and/or _status area_.

```python
# Normal progress at 60%
print(term.progress_bar('normal', 60))

# Enter error state
print(term.progress_bar('error'))

# Indeterminate
print(term.progress_bar('indeterminate'))

# Paused
print(term.progress_bar('pause'))

# Remove the indicator
print(term.progress_bar('clear'))
```

### OSC 52 Clipboard

```python
# detection
if term.does_osc52_clipboard():
    print("Terminal supports clipboard access")


# copy to clipboard
term.clipboard_copy('Hello from blessed!')

# reading from clipboard
text = term.clipboard_paste()
if text is not None:
    print(f"Clipboard: {text}")
```

> [!NOTE]
> need permission for reading clipboard in some terminal
> default timeout = 10s, return None when expired

### Styles

- bold              Turn on ‘extra bright’ mode.
- dim               Enable dim (half-bright) mode.
- reverse           Switch fore and background attributes.
- strikethrough     Enable strikethrough mode.
- no_strikethrough  Disable strikethrough mode.
- underline         Enable underline mode.
- no_underline      Disable underline mode.
- normal            Reset attributes to default.

> [!NOTE] inverse styles
> underline >< no_underline
> __bold__, reverse >< normal (cancel any custom colors)

### full-screen mode

```python
# Switch to alternate screen, previous screen is stored by terminal driver.
print(term.enter_fullscreen())

# Switch back to standard screen, restoring the same terminal screen.
print(term.exit_fullscreen())

# use with context manager
with term.fullscreen(), term.cbreak():
    print(term.move_y(term.height // 2) +
          term.center('press any key').rstrip())
    term.inkey()
```


### Line Wrap Control

```python
print(term.enable_line_wrap())
print(term.disable_line_wrap())

with term.no_line_wrap():
    print(term.move_x(0) + 'X' * (term.width * 3))
```

## Colors

[All Terminal colors](https://blessed.readthedocs.io/en/latest/colors.html#id3) 

```python
print(term.orangered + 'All systems are offline' + term.normal)
print(f'{term.orangered}All systems are offline{term.normal}')
print(term.orangered('All systems are offline'))

# background color with prefix `on_`
print(term.on_lawngreen("welcome to my app"))

# foreground + background by `_on_`
print(term.red_on_yellow("VN vo dich"))

# rgb and hex color
print(term.color_rgb(255, 0, 255)("Bright Magenta"))
print(term.color_hex("#cafe00")("green goo"))
```

### Querying Terminal color

```python
fg_hex = term.get_fgcolor_hex()
bg_hex = term.get_bgcolor_hex()

bg_rgb = term.get_bgcolor(bits=8)
fg_rgb = term.get_fgcolor(bits=8)
```

## Keyboard Input

TODO: 
[keyboard input](https://blessed.readthedocs.io/en/latest/keyboard.html) 

> [!NOTE]
> `cbreak()` *context manager* enable _immediate_ key detection
> `inkey()` ->`Keystroke` object. `timeout` parameter default = 1 s

### Keystroke

> [!NOTE]
> inherits from `str` => can compare with other strings
> `is_sequence` -> detect special keys
> `name` -> special keys name (e.g..,KEY_F1, KEY_CTRL_Q)
> magic methods `keystroke.is_f1()` or `keystroke.is_key_crtl('q')`

#### Special Keys


