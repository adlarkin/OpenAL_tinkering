#include <stdlib.h>

#include <iostream>
#include <string>

#include <al.h>
#include <alc.h>
#include <alut.h>

void reportError(const std::string &_errorContext,
                 ALenum _code=ALUT_ERROR_NO_ERROR)
{
  _code = _code == ALUT_ERROR_NO_ERROR ? alutGetError() : _code;
  std::cerr << _errorContext << alutGetErrorString(_code) << std::endl;
  exit(EXIT_FAILURE);
}

void checkAlError(const std::string &_errorContext)
{
  auto error = alGetError();
  if (error != AL_NO_ERROR)
    reportError(_errorContext, error);
}

int main()
{
  // initialize a context on the default device
  if (!alutInit(NULL, NULL))
    reportError("alutInit error: ");

  // create a buffer that contains sound data from a file
  auto buf = alutCreateBufferFromFile("./../test.wav");
  if (buf == AL_NONE)
    reportError("alutCreateBufferFromFile error: ");
    //std::cerr << "failure occurred when loading the wav file" << std::endl;

  // create a source
  ALsizei num_sources = 1;
  ALuint source;
  alGenSources(num_sources, &source);
  checkAlError("alGenSources error: ");

  // attach buffer to the source
  alSourcei(source, AL_BUFFER, buf);
  checkAlError("alSourcei error: ");

  // play the sound
  alSourcePlay(source);
  checkAlError("alSourcePlay error: ");

  // wait for the source to finish playing
  ALint source_state;
  do
  {
    alGetSourcei(source, AL_SOURCE_STATE, &source_state);
    checkAlError("alGetSourcei error: ");
  } while (source_state == AL_PLAYING);

  // shut down the source since this wasn't created by alut
  alDeleteSources(num_sources, &source);
  checkAlError("alDeleteSources error: ");

  // shut down alut
  // (this also closes any OpenAL device/context created bu alutInit)
  if (!alutExit())
    reportError("alutExit error: ");

  return EXIT_SUCCESS;
}
