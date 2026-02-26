#include<SDL2/SDL.h>
#include<iostream>
int main(){

    SDL_AudioSpec spec;
    Uint8* audio_buf;
    Uint32 audio_len;

    SDL_InitSubSystem(SDL_INIT_AUDIO);
    

    SDL_AudioSpec* sound = SDL_LoadWAV("mario.wav", &spec , &audio_buf, &audio_len);
    if (sound == NULL){
        std::cout<<"failed to load .wav file\n";
    }
    else{
        std::cerr<<"audio loaded sucessfully\n";
    }

    return 0;
}