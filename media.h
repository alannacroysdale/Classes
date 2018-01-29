#include <iostream>
#include <string.h>

using namespace std;
#ifndef MEDIA_H
#define MEDIA_H

class Media {
 public:
  Media();
  //initiates variables and functions
  string title;
  string publisher;
  string artist;
  string director;
  int rating;
  int duration;
  int year;

  string getTitle();
  string getPublisher();
  string getArtist();
  string getDirector();
  int getRating();
  int getDuration();
  int getYear();
  int getID();

  void setYear(int year);
  void setTitle(string title);
  void setPublisher(string publisher);
  void setArtist(string artist);
  void setDirector(string director);
  void setRating(int rating);
  void setDuration(int duration);
 protected:
  int id;
};

#endif
