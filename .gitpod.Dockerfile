FROM gitpod/workspace-full

RUN git clone "https://github.com/emscripten-core/emsdk.git" /home/gitpod/.emsdk \
&& cd $HOME/.emsdk \
&& ./emsdk install latest \
&& ./emsdk activate latest \
&& bash -c "source /home/gitpod/.emsdk/emsdk_env.sh"

RUN printf "\nsource /home/gitpod/.emsdk/emsdk_env.sh\nclear\n" >> $HOME/.bash_profile
