#include <iostream>     
#include <algorithm>	
#include <vector>       
#include <string>       

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
	void pop() {
		if (!songs.empty())
		{
			songs.erase(songs.end() - 1);
		}
	}
	void view_queue() {
		for (int i = 0; i < songs.size(); i++) {
			cout << i + 1 << ". " << songs[i].get_title() << " - " << songs[i].get_artist() << endl;
		}
	}
	void currently_playing() {
		int i = 0;
		if (!songs.empty()) {
			cout << "Now playing: " << endl;
			cout << songs[i].get_title() << " - " << songs[i].get_artist() << endl;
		}
		else {
			cout << "Playlist is empty" << endl;
		}
	}
	int size() {
		return songs.size();
	}
};
int main()
{
	Song song;
	song.set_title("Disasterpiece");
	song.set_artist("Slipknot");

	Song song1;
	song1.set_title("Repentless");
	song1.set_artist("Slayer");

	Song song2;
	song2.set_title("Doomsday");
	song2.set_artist("MF DOOM");


	Queue queue;
	queue.enqueue(song);
	queue.enqueue(song1);
	queue.enqueue(song2);

	Song unknownSongArtist;
	queue.enqueue(unknownSongArtist);

	Queue queue1;
	queue1 = queue;

	cout << "Playlist 1: " << endl;
	queue.view_queue();

	cout << "Playlist 2(Dequeue): " << endl;
	queue1.dequeue();
	queue1.view_queue();

	cout << "Playlist 3(Pop): " << endl;
	queue.pop();
	queue.view_queue();

	queue.currently_playing();

	cout << "Do you want to make a playlist ? [y/n]" << endl;
	char yn;
	cin >> yn;
	if (yn == 'y')
	{
		int q = 0;
		cout << "Enter song in the format [title] - [artist] (type 'Quit' to exit): " << endl;
		while (true)
		{
			string new_song_input;
			string enterTitle, enterArtist;


			getline(cin, new_song_input);

			if (new_song_input == "Quit")
			{
				break;
			}

			// Find the position of '-' 
			int split_position = new_song_input.find("-");

			//string::npos == until the end of the string 
			if (split_position != string::npos)
			{
				enterTitle = new_song_input.substr(0, split_position - 1);
				enterArtist = new_song_input.substr(split_position + 2);

				Song new_song;
				new_song.set_title(enterTitle);
				new_song.set_artist(enterArtist);
				queue.enqueue(new_song);
				cout << "Successfully added " << enterTitle << " - " << enterArtist << endl;
				q++;
			}
			else
			{
				if (q > 0)
				{
					cout << "Invalid input. Please enter the song in the format [title] - [artist]." << endl;
				}
			}
		}
	}

	queue.view_queue();

	return 0;
}
