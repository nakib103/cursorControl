# cursorControl: Powering the Disabled

![Build Status](https://github.com/nakib103/cursorControl/actions/workflows/cmake.yml/badge.svg)
[![Slack join](https://img.shields.io/badge/slack-join-green)](https://join.slack.com/t/cursorcontrolgroup/shared_invite/zt-qwzhxi4m-iNh3UmEdWQGDRcINwEd4EQ)

The goal of cursorControl is to enable a disabled person to use the technology the same way a non-disabled person would do. 

## Design Principle
cursorControl is an event-driven application and designed to be modular so that more functionalities can be added to it with greater flexibility. There are basically three parts of the system - 
- Input buffers
- Event processors
- Controllers

For example, to enable a disabled person who have not voluntary movement under the neck to control a mouse cursor we will use a video input buffer, a mouse mover event processor, and a mouse movement controller. Video input buffer stores the input from input device (webcam), the mouse mover event processor processes the frames and set the mouse contollers state to desired cursor location, and finally the mouse controller moves the cursor.

## Installation
#### Building for source

For production release:

```sh
gulp build --prod
```

Generating pre-built zip archives for distribution:

```sh
gulp build dist --prod
```
## Contributing
Want to contribute? Great!
## License

GNU Public License v3