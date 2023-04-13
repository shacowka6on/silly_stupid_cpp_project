#include <iostream>
#include <vector>
using namespace std;

class Song {
private:
	string title;
	string artist;
	string file_location;

public:

	Song() {
		title = "Unknown song";
		artist = "Unknown artist";
		file_location = "path/to/default/folder/song.mp3";
	}
	void set_title(string new_title) {
		title = new_title;
	}
	void set_artist(string new_artist) {
		artist = new_artist;
	}
	string get_title() {
		return title;
	}
	string get_artist() {
		return artist;
	}
};
class Queue {
private:
	vector<Song> songs;
public:
	Queue() {
		
	}
	void enqueue(Song song) {
		songs.push_back(song);
	}
	void dequeue() {
		if (!songs.empty())
		{
			songs.erase(songs.begin());
		}
	}
	void view_queue() {
		for (int i = 0; i < songs.size(); i++) {
			cout << i + 1 << ". " << songs[i].get_title() << " - " << songs[i].get_artist() << endl;
		}
	}
	int size() {
		return songs.size();
	}
};


int main()
{
	/*Song song;
	Song song1;
	song.set_title("Likin Park");
	cout << "Current song: " << song1.get_title() << endl;*/

	Song song;
	song.set_title("Disasterpiece");
	song.set_artist("Slipknot");

	Queue queue;
	queue.enqueue(song);

	Song unknownSongArtist;

	queue.enqueue(unknownSongArtist);

	queue.view_queue();



	return 0;
}

