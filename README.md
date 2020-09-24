# OpenAL_tinkering

Testing some basic audio capabilities with OpenAL.

[OpenAL-Soft](https://github.com/kcat/openal-soft) and [ALUT](http://distro.ibiblio.org/rootlinux/rootlinux-ports/more/freealut/freealut-1.1.0/doc/alut.html) are used. The [OpenAL documentation](https://www.openal.org/documentation/) is also a useful resource.

## Requirements

If you plan to use this repository locally (NOT through Docker), you'll need to install OpenAL and ALUT.
On Ubuntu, you can do this with the following command:

```bash
sudo apt update && sudo apt install -y libopenal-dev libalut-dev
```

## Usage

### Docker

The [docker/](docker/) directory of this repository contains files that allow you to use OpenAL inside of a Docker container.

### Building

CMake can be used:

```bash
mkdir build
cd build
cmake ..
make
```

### Running

Two executables are created:
1. `alut_demo`
    - This is a demo copied from the [ALUT documentation](http://distro.ibiblio.org/rootlinux/rootlinux-ports/more/freealut/freealut-1.1.0/doc/alut.html).
2. `test_exe`
    - This is a more complete example that expands on the code used to create `alut_demo`.

Run either executable as follows (no command line arguments are needed):

```bash
./<executable-name>
```

You should hear audio played to a device momentarily, assuming that an audio device exists and can be connected to.

## Other things to note

There's a [ycm config file](.ycm_extra_conf.py) in this repository that uses the [ycm vim plugin](https://github.com/ycm-core/YouCompleteMe) to give "intellisense" functionality.
This repository's OpenAL [docker setup](docker/) also assumes that the ycm plugin is used, and this ycm config file can be used inside of Docker.
