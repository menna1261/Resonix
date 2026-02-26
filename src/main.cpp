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

    SDL_AudioDeviceID dev = SDL_OpenAudioDevice(NULL, 0,&spec , &spec, 0);
    if(dev == 0){
        std::cout<<"Failed to open file\n";
    }
    else{
        std::cout<<"opened file\n";

    }

    std::cout<<"format : "<<spec.format<<" "<<"channels: " <<spec.channels<<" "<<"freq: "<<spec.freq<<"\n";
    int sample_count = audio_len / 2;
    Sint16* samples = (Sint16*)audio_buf;

    float volume = 0.1;

    for(int i =  0; i<sample_count;i++){

        float result = samples[i] * volume;

        //Clamp result between 32767 and -32768
        if(result > 32767 ) result = 32767 ;
        if(result < -32768) result = -32768;

        samples[i] = result;
    }

    SDL_QueueAudio(dev, audio_buf, audio_len);
    SDL_FreeWAV(audio_buf);          
    SDL_PauseAudioDevice(dev, 0);    
    SDL_Delay(5000);
    SDL_CloseAudioDevice(dev);

    
    return 0;
}