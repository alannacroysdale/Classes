#include <iostream>
#include <string.h>
#include "game.h"
#include "music.h"
#include "movie.h"
#include <vector>

using namespace std;

vector<Media*> database;
string input = " ";

//state functions so that they can be used
vector<Media*> ADD(vector<Media*>);
void SEARCH(vector<Media*>);
vector<Media*> DELETE(vector<Media*>);

int main()
{
  string input = "";
  vector<Media*> database;
  //make a boolean for looping
  bool quit = false;
  while (quit == false) {
    cout << "Enter 'add' to add a media to the database, 'search' to search for a media, 'delete' to delete a media or 'quit' to exit the program" << endl;
    cin >> input;
    cout << "you entered '" << input << "'" << endl;
    if (input == "add") {
      ADD(database);
    }
    //ends the program
    else if (input == "quit") {
      quit = true;
    }
    else if (input == "search") {
      SEARCH(database);
    }
    else if (input == "delete") {
      DELETE(database);
    }
  }
  return 0;
}
//adds a Media* to the database and then returns the database
vector<Media*> ADD(vector<Media*>)
{
  string input = "";
  int intinput = 0;
  string type = "";
  Media* media;
  //ensures that the input entered is music, movie or game
  while (input != "music" && input != "movie" && input != "game") {
    cout << "Is the media a movie, music or a video game? Enter 'music', 'movie' or 'game'." << endl;
    cin >> input;
    if (input == "music") {
      Music* music = new Music();
      media = music;
      type = "music";
    }
    else if (input == "game"){
      Game* game = new Game();
      media = game;
      type = "game";
    }
    else if (input == "movie") {
      Movie* movie = new Movie();
      media = movie;
      type = "movie";
    }
  }
  //adds media to the database
  database.push_back(media);
  //gets the user to input all details about the media and those details are set
  cout << "Enter the title" << endl;
  cin >> input;
  media->setTitle(input);
  cout << "Enter the year the media was created" << endl;
  cin >> intinput;
  media->setYear(intinput);
  if (type == "movie" || type == "game")
    {
      cout << "Enter the rating out of 5 stars" << endl;
      cin >> intinput;
      media->setRating(intinput);
    }
  if (type == "game" || type == "music")
    {
      cout << "Enter the name of the publisher" << endl;
      cin >> input;
      media->setPublisher(input);
    }
  if (type == "music" || type == "movie")
    {
      cout << "Enter the duration in minutes" << endl;
      cin >> intinput;
      media->setDuration(intinput);
    }
  if (type == "music")
    {
      cout << "Enter the name of the artist" << endl;
      cin >> input;
      media->setArtist(input);
    }
  if (type == "movie")
    {
      cout << "Enter the name of the director" << endl;
      cin >> input;
      media->setDirector(input);
    }
  return database;
}

//searches for a media based on its title or year without changing the database
void SEARCH(vector<Media*>) {
  string input;
  int intinput;
  bool exists = false;
  //ensures that input is title or year
  while (input != "title" && input != "year") {
    cout << "Search for a title or a year?" << endl;
    cin >> input;
  }
    if (input == "title") {
        cout << "Enter the title" << endl;
        cin >> input;
	//iterates through the database in order to search for media with that title
        vector<Media*>::iterator n, end;
        for (n = database.begin(), end = database.end(); n != end; ++n) {
            if ((*n)->getTitle() == input) {
	      exists = true;
	      //gets all the data from the media that was found
                string a = (*n)->getArtist();
                string p = (*n)->getPublisher();
                string d = (*n)->getDirector();
                int l    = (*n)->getDuration();
                int r    = (*n)->getRating();
                int y    = (*n)->getYear();
                cout << "This media matched." << endl;
		//returns all that data
                if (a != "") {
                    cout << "The artist is " << a << "." << endl;
                }
                if (p != "") {
                    cout << "The publisher is " << p << "." << endl;
                }
                if (d != "") {
                    cout << "The director is " << d << "." << endl;
                }
                if (l != 0) {
                    cout << "The duration is " << l << " minutes." << endl;
                }
                if (r != 0) {
                    cout << "The rating is " << r << " out of 5 stars." << endl;
                }
                cout << "The media was made in " << y << endl;
            }
        }
    } //same as searching for title, except for a year
    else if (input == "year") {
        cout << "Enter the year" << endl;
        cin >> intinput;
	vector<Media*>::iterator n, end;
        for (n = database.begin(), end = database.end(); n != end; ++n) {
            if ((*n)->getYear() == intinput) {
                exists = true;
                string a = (*n)->getArtist();
                string p = (*n)->getPublisher();
                string d = (*n)->getDirector();
                int l    = (*n)->getDuration();
                int r    = (*n)->getRating();
                string t    = (*n)->getTitle();
                cout << "This media matched." << endl;
                if (a != "") {
                    cout << "The artist is " << a << "." << endl;
                }
                if (p != "") {
                    cout << "The publisher is " << p << "." << endl;
                }
                if (d != "") {
                    cout << "The director is " << d << "." << endl;
                }
                if (l != 0) {
                    cout << "The duration is " << l << " minutes." << endl;
                }
                if (r != 0) {
                    cout << "The rating is " << r << " out of 5 stars." << endl;
                }
                cout << "The title is " << t << endl;
            }
        }
    }//if there aren't any media matching the search inform user
    if (exists == false) {
      cout << "There are no media matching your search" << endl;
    }
}
//searches for a media based on its title and year and then deletes it
vector<Media*> DELETE (vector<Media*>) {
  bool exists = false;
  string input;
  int intinput;
  cout << "Enter the title" << endl;
  cin >> input;
  string title = input;
  cout << "Enter the year" << endl;
  cin >> intinput;
  int year = intinput;
  vector<Media*>::iterator n, end;
  for (n = database.begin(), end = database.end(); n != end; ++n) {
    if ((*n)->getTitle() == title && (*n)->getYear() == year) {
      exists = true;
      cout << "Are you sure you would like to delete a media? Enter 'cancel' to not do so, or anything else to continue." << endl;
      cin >> input;
      if (input == "cancel")
      {
	return database;
      }
      delete *n; // Deletes what n is pointing to
      database.erase(n);
    }
  }
  //if there are no media with that title in year in the database, inform user
  if (exists == false) {
    cout << "There are no media with that title and year." << endl;
  }
  return database;
}
