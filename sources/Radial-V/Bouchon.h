

#ifndef BOUCHONCLASS_H_INCLUDED
#define BOUCHONCLASS_H_INCLUDED

class Bouchon
{
    public:
        Bouchon();
        uint8_t  begin();
        bool     begin(int dummy1, const uint8_t& dummy2);
        uint8_t  playMP3(char* dummy);
        bool     isPlaying();
        void     setVolume(int dummy1, int dummy2);
        void     stopTrack();
        void     vs_init();
        uint8_t  getEarSpeaker();
        void     setEarSpeaker(uint8_t dummy);
        void     trackTitle(char*  dummy);
        void     trackArtist(char* dummy);
        void     trackAlbum(char*  dummy);
        uint16_t getDifferentialOutput();
        void     setDifferentialOutput(uint16_t dummy);
        void     setMonoMode(uint16_t dummy);
        uint16_t getMonoMode();
        int      getState();
        void     initErrorHalt();
        bool     chdir(char* dummy);
        void     errorHalt(char* dummy);

        private:
        uint16_t  MonoMode=0;
        uint16_t  DifferentialOutput=0;
        uint8_t   EarSpeaker=0;
        int       Playing=300-2;
};

#endif // BOUCHONCLASS_H_INCLUDED


Bouchon::Bouchon(){};
uint8_t  Bouchon::begin(){return 0;};
bool     Bouchon::begin(int dummy1, const uint8_t& dummy2){return true;};
uint8_t  Bouchon::playMP3(char* dummy){Playing=0;return 0;};
bool     Bouchon::isPlaying(){Playing++; return (Playing!=300);};   // 300 = 1 minute
void     Bouchon::setVolume(int dummy1, int dummy2){};
void     Bouchon::stopTrack(){Playing=0;};
void     Bouchon::vs_init(){};
void     Bouchon::setEarSpeaker(uint8_t dummy){EarSpeaker=dummy;};
uint8_t  Bouchon::getEarSpeaker(){return EarSpeaker;};
void     Bouchon::trackTitle(char*  dummy){}; //strcpy(dummy,"Current title");};
void     Bouchon::trackArtist(char* dummy){}; //strcpy(dummy,"Current artist");};
void     Bouchon::trackAlbum(char*  dummy){}; //strcpy(dummy,"Current album");};
void     Bouchon::setDifferentialOutput(uint16_t dummy){DifferentialOutput=dummy;};
uint16_t Bouchon::getDifferentialOutput(){return DifferentialOutput;};
void     Bouchon::setMonoMode(uint16_t dummy){MonoMode=dummy;};
uint16_t Bouchon::getMonoMode(){return MonoMode;};
int      Bouchon::getState() {return 0;};       // renvoyer le code qui correspond à ready
void     Bouchon::initErrorHalt(){Serial.println("Bouchon::initErrorHalt");};
bool     Bouchon::chdir(char* dummy){return true;};
void     Bouchon::errorHalt(char* dummy){};



