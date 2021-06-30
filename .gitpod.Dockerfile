FROM gitpod/workspace-full

RUN git clone "https://github.com/emscripten-core/emsdk.git" $HOME/.emsdk \
&& cd $HOME/.emsdk \
&& ./emsdk install latest \
&& ./emsdk activate latest
RUN sudo apt-get update \
&& sudo apt install mesa-utils libgl-dev \
&& sudo apt install libglbinding-dev \
&& sudo apt-get install freeglut3-dev \