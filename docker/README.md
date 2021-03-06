# Docker for OpenAL

These files provide a way to develop audio applications inside of Docker.

The [Dockerfile](Dockerfile) is straightforward, but some work had to be done in [run.bash](run.bash) to enable audio capabilities inside of a Docker container.

## Usage

Below shows how to build the Docker image and start a container that uses this image.
This image assumes that you have a `.vimrc` in your `$HOME` directory (`~/`), so if you don't, make sure to modify the context of `build.bash` and the copying of `.vimrc` in the Dockerfile accordingly.
The Dockerfile also assumes that the [ycm](https://github.com/ycm-core/YouCompleteMe) plugin for vim is used.
If you don't use this plugin, you can remove the steps for building this plugin from the [Dockerfile](Dockerfile).

### Building the Docker Image

```bash
./build.bash
```

### Starting a container from the built image

The code from this repository is loaded into the Docker container at runtime as a volume.
This means that you need to provide the location of this repository when you start the container.
Replace `$REPO_DIR` in the command below with the location of the repository on your machine.

_For example: if I cloned the repository to my `$HOME` (`~/`) directory, `$REPO_DIR` would become `~/`._

```bash
./run.bash openal_testing $REPO_DIR
```
