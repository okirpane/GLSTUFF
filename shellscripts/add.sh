git clone "https://github.com/emscripten-core/emsdk.git" $HOME/.emsdk

cd $HOME/.emsdk

./emsdk install latest

./emsdk activate latest

source "/home/gitpod/.emsdk/emsdk_env.sh"

echo 'source "/home/gitpod/.emsdk/emsdk_env.sh"' >> $HOME/.bash_profile