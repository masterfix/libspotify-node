#ifndef SPOTIFY_SEARCH_H_
#define SPOTIFY_SEARCH_H_

#include "index.h"

class SearchResult : public ObjectWrap {
 public:
  static Persistent<FunctionTemplate> constructor_template;

  static void Initialize(Handle<Object> target);
  explicit SearchResult(sp_session* session, sp_search* search);
  static Handle<Value> New(const Arguments& args);
  static Local<Object> New(sp_session* session, sp_search *search);

  static Handle<Value> LoadedGetter(Local<String> property,
                                    const AccessorInfo& info);
  static Handle<Value> TracksGetter(Local<String> property,
                                    const AccessorInfo& info);
  static Handle<Value> AlbumsGetter(Local<String> property,
                                    const AccessorInfo& info);
  static Handle<Value> ArtistsGetter(Local<String> property,
                                     const AccessorInfo& info);
  static Handle<Value> TotalTracksGetter(Local<String> property,
                                         const AccessorInfo& info);
  static Handle<Value> QueryGetter(Local<String> property,
                                   const AccessorInfo& info);
  static Handle<Value> DidYouMeanGetter(Local<String> property,
                                        const AccessorInfo& info);
  static Handle<Value> URIGetter(Local<String> property,
                                 const AccessorInfo& info);
 protected:
  sp_session* session_; 
  sp_search* search_;
};

#endif
