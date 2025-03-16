# NintendoSDK-NEX

This is a decompilation of the NEX networking library used on the Nintendo Switch.

Nintendo's NEX implementation is directly based on Rendez-Vous by Quazal.

### Contributing

Switch versions of NEX use Link Time Optimization which lets functions inline between classes. Since we're using the same Clang version that NEX was built with, LTO works the same for us as it did for Nintendo.

[The Binding of Issac: Afterbirth+][issac] contains a debug version of NEX 4.0.2. This version has asserts in almost every function and many functions that would be optimized by LTO aren't because function sizes are inflated. The file paths in this project are taken from asserts in this game. A full list of file paths can be found in `docs/PATHS.md`.

Minecraft: Wii U Edition contains symbols for NEX 3.9.1/3.10.0 and doesn't use LTO, which makes it a great resource for finding inlined functions.

### Supported Versions
* `4.1.2-apprs` (used by Super Mario Odyssey v1.0.0)

### TODO

[issac]: https://www.nintendo.com/us/store/products/the-binding-of-isaac-afterbirth-plus-switch/