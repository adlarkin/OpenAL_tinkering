FROM ubuntu:focal

# setup timezone (appears to be needed for vim)
RUN echo 'Etc/UTC' > /etc/timezone && \
    ln -s /usr/share/zoneinfo/Etc/UTC /etc/localtime && \
    apt-get update && \
    apt-get install -q -y --no-install-recommends tzdata && \
    rm -rf /var/lib/apt/lists/*

# install packages needed for development
RUN apt-get -qq update && apt-get -y install \
  cmake \
  git \
  libopenal-dev \
  libalut-dev \
  pkg-config \
  sudo \
  vim \
  && rm -rf /var/lib/apt/lists/*

# Add a user with the same user_id as the user outside the container
# Requires a docker build argument `user_id`
ARG user_id
ENV USERNAME developer
RUN useradd -U --uid ${user_id} -ms /bin/bash $USERNAME \
 && echo "$USERNAME:$USERNAME" | chpasswd \
 && adduser $USERNAME sudo \
 && echo "$USERNAME ALL=NOPASSWD: ALL" >> /etc/sudoers.d/$USERNAME
USER $USERNAME

# create a location where development can be done ("workspace")
RUN mkdir -p ~/ws/

# setup vim development environment inside of Docker
WORKDIR /home/$USERNAME
COPY .vimrc .
RUN git clone https://github.com/VundleVim/Vundle.vim.git ~/.vim/bundle/Vundle.vim \
  && vim +PluginInstall +qall \
  # the following steps are for a C++ ycm configuration (previous steps set up plugins)
  && sudo apt-get -qq update && sudo apt-get -y install build-essential cmake vim python3-dev \
  && cd ~/.vim/bundle/YouCompleteMe/ && python3 install.py --clangd-completer \
  && sudo rm -rf /var/lib/apt/lists/*

# start in the workspace when a Docker container is started
WORKDIR /home/$USERNAME/ws
