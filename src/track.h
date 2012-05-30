#ifndef SPOTIFY_TRACK_H_
#define SPOTIFY_TRACK_H_

#include "index.h"

class Album;

class Track : public ObjectWrap {
 public:
  static Persistent<FunctionTemplate> constructor_template;

  static void Initialize(Handle<Object> target);

  explicit Track(sp_session* session, sp_track *track);
  ~Track();

  static Handle<Value> New(const Arguments& args);
  static Handle<Value> New(sp_session* session, sp_track *track);

  GETTER_H(LoadedGetter);
  GETTER_H(AlbumGetter);
  GETTER_H(ArtistsGetter);
  GETTER_H(UriGetter);

  sp_session* session_;
  sp_track* track_;
 protected:
  bool SetupBackingTrack();
  Album *album_;
};

#endif
