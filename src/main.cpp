#include "generateArtefacts.h"

int main(int argc,char *argv[]){
	
	GenerateArtefacts *ga = new GenerateArtefacts();

	string ok;
	int op;
	string ch;

	if(argc == 3){
		string artefact(argv[1]);
		string name(argv[2]);
		char const* tmp_home = getenv("HOME");
		string home(tmp_home);
		
		if(artefact.compare("midiMelody") == 0){
			cout << "Generating midiMelody" << endl;
			
			MidiMelody *md = new MidiMelody();

			md->melodyGenerator(name, home + "/MUSIC_DEAF/music_for_deaf_files/audios/" + name + ".wav",
			home + "/MUSIC_DEAF/music_for_deaf_files/midis/");

			delete md;
			return 0;
		}

		if(artefact.compare("aurisStream") == 0){
			cout << "Generating aurisStream" << endl;

			AurisStream *as = new AurisStream();
			MidiToNotes *mtn = new MidiToNotes();

			mtn->midiNotes(name, home + "/MUSIC_DEAF/music_for_deaf_files/midis/" + name + ".mid", "/tmp/");
			as->streamAurisGenerate(name, home + "/MUSIC_DEAF/music_for_deaf/auris-core/auris-stream/file/configure.txt",
						   		 "/tmp/" + name + ".txt", 0, home + "/MUSIC_DEAF/music_for_deaf_files/auris_melodies/");

			delete as;
			delete mtn;
			return 0;
		}

		if(artefact.compare("playAuris")){
			cout << "Generating playAuris" << endl;
			
			PlayAuris *pl = new PlayAuris();
			SendSignalBeagle *ss = new SendSignalBeagle();
			
			if(name.compare("off") == 0)
				ss->setAllPinsOff();
			if(name.compare("off") != 0){
				cout << "MUSIC ------------>" << name << endl;
				pl->playAurisMelody(home + "/MUSIC_DEAF/music_for_deaf_files/auris_melodies/" + name + ".txt", 1);
			}

			delete ss;
			delete pl;
			return 0;
		}
	}

	while(1){
		cout << "Choose what you want to do:" << endl;
		cout << "[1] - Generate MIDI Melody" << endl;
		cout << "[2] - Generate Auris Stream" << endl;
		cout << "[3] - Play Auris Stream" << endl;
		cout << "[0] - Out" << endl;
		
		cin.clear();
		cin >> op;

		if(op == 1){
			system("clear");
			ga->generateMidiMelody();
		}
		
		if(op == 2){
			system("clear");
			ga->generateAurisStream();
		}

		if(op == 3){
			system("clear");
			ga->generatePlayAuris();
		}

		if(op == 0){
			break;
		}

		cout << "Press any key and ENTER" << endl;
		cin>>ch;
		if(ch.compare("\n")){
			system("clear");
		}
	}

	return 0;
}
