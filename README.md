# openal_tinkering

Testing some basic audio capabilities with OpenAL.

[OpenAL-Soft](https://github.com/kcat/openal-soft) and [ALUT](http://distro.ibiblio.org/rootlinux/rootlinux-ports/more/freealut/freealut-1.1.0/doc/alut.html) are used. The [OpenAL documentation](https://www.openal.org/documentation/) is also a useful resource.

## Usage

### Docker

TODO fill this in

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
