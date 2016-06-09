#include "generateArtefacts.h"

void GenerateArtefacts::generateMidiMelody(){

	ListFiles *lf = new ListFiles();
	MidiMelody *md = new MidiMelody();

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);
	int choose;
	string ext(".mp3");

	vector<string> ret;

	cout << "Chose a file to generate MIDI Melody: " << endl;
	lf->listExtension(home + "/MUSIC_DEAF/music_for_deaf_files/audios", ext, &ret);

	cin.clear();
	if(cin >> choose){
		string name(ret.at(choose));

		//remove extension of name
		std::string::size_type i = name.find(ext);
		if (i != std::string::npos)
	   		name.erase(i, ext.length());

		md->melodyGenerator(name, home + "/MUSIC_DEAF/music_for_deaf_files/audios/" + name + ext,
		home + "/MUSIC_DEAF/music_for_deaf_files/midis/");
	}

	ret.clear();

	delete lf;
	delete md;	
}

void GenerateArtefacts::generateAurisStream(){

	ListFiles *lf = new ListFiles();
	AurisStream *as = new AurisStream();
	MidiToNotes *mtn = new MidiToNotes();

	vector<string> ret;

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);
	int choose;
	string ext2(".mid"), ext3(".txt");

	cout << "Chose a file to generate Auris Stream: " << endl;
	lf->listExtension(home + "/MUSIC_DEAF/music_for_deaf_files/midis", ext2, &ret);

	cin.clear();
	if(cin >> choose){
		string name(ret.at(choose));

		//remove extension of name
		std::string::size_type i = name.find(ext2);
		if (i != std::string::npos)
	   		name.erase(i, ext2.length());

	   	mtn->midiNotes(name, home + "/MUSIC_DEAF/music_for_deaf_files/midis/" + name + ext2, "/tmp/");
		as->streamAurisGenerate(name, home + "/MUSIC_DEAF/music_for_deaf/auris-core/auris-stream/file/configure.txt",
						   		 "/tmp/" + name + ext3, 0, home + "/MUSIC_DEAF/music_for_deaf_files/auris_melodies/");
	}

	ret.clear();

	delete lf;
	delete as;
	delete mtn;
}

void GenerateArtefacts::generatePlayAuris(){
	PlayAuris *pl = new PlayAuris();
	ListFiles *lf = new ListFiles();

	char const* tmp_home = getenv("HOME");
	string home(tmp_home);
	int choose;

	vector<string> ret;

	cout << "Chose a file to Play Auris Melody: " << endl;
	lf->listExtension(home + "/MUSIC_DEAF/music_for_deaf_files/auris_melodies", ".txt", &ret);

	cin.clear();
	if(cin >> choose){
		string name(ret.at(choose));

		pl->playAurisMelody(home + "/MUSIC_DEAF/music_for_deaf_files/auris_melodies/" + name, 1);
	}

	ret.clear();

	delete lf;
	delete pl;
}

