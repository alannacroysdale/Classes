#include <iostream>
#include <string.h>
#include "Media.h"

using namespace std;

Media::Media() {
  //define variables to a standard value
  id = 0;
  title = "";
  publisher = "";
  artist = "";
  director = "";
  rating = 0;
  duration = 0;
  year = 0;
}
//define functions
string Media::getTitle() {
  return title;
}

string Media::getPublisher() {
  return publisher;
}

string Media::getArtist() {
  return artist;
}

string Media::getDirector() {
  return director;
}

int Media::getRating() {
  return rating;
}

int Media::getDuration() {
  return duration;
}

int Media::getYear() {
  return year;
}

int Media::getID() {
  return id;
}

void Media::setTitle(string newTitle) {
  title = newTitle;
}

void Media::setPublisher(string newPublisher) {
  publisher = newPublisher;
}

void Media::setArtist(string newArtist) {
  artist = newArtist;
}

void Media::setDirector(string newDirector) {
  director = newDirector;
}

void Media::setRating(int newRating) {
  rating = newRating;
}

void Media::setDuration(int newDuration) {
  duration = newDuration;
}

void Media::setYear(int newYear) {
  year = newYear;
}
