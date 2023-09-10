# Aaron's Aurora Lily58's Keymap

## Todo

- 

## Notes

- This directory started as a copy of the `keymaps/default` directory.
- The `keymap.json` file was edited to reflect the initial layout I wanted.
- The `keymap.json` file was converted to a `.c` file, open "QMK MSYS", then:

```sh
cd /d/qmk_firmware/keyboards/splitkb/aurora/lily58/keymaps/aaron/
qmk json2c -o keymap.c keymap.json

# If a JSON file is present, the C file is ignored, so rename the JSON file
mv keymap.json keymap.json.archive
```

## Refs

- [keycodes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)
- [encoders](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_encoders.md)
- [RGB lighting](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_rgblight.md)
- [OLED](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_oled_driver.md)
- [Split keyboard features](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md)