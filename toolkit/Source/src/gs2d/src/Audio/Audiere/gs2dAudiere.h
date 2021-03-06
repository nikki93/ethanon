/*--------------------------------------------------------------------------------------
 Ethanon Engine (C) Copyright 2008-2012 Andre Santee
 http://www.asantee.net/ethanon/

	Permission is hereby granted, free of charge, to any person obtaining a copy of this
	software and associated documentation files (the "Software"), to deal in the
	Software without restriction, including without limitation the rights to use, copy,
	modify, merge, publish, distribute, sublicense, and/or sell copies of the Software,
	and to permit persons to whom the Software is furnished to do so, subject to the
	following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED,
	INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
	PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
	HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF
	CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE
	OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
--------------------------------------------------------------------------------------*/

#ifndef GS2D_AUDIERE_H_
#define GS2D_AUDIERE_H_

#include "../../gs2daudio.h"
#include "audiere/src/audiere.h"

namespace gs2d {

class AudiereContext : public Audio
{
	audiere::AudioDevicePtr m_device;
	bool CreateAudioDevice(boost::any data);

	boost::weak_ptr<AudiereContext> weak_this;

	AudiereContext();

	float m_globalVolume;

public:
	static boost::shared_ptr<AudiereContext> Create(boost::any data);

	AudioSamplePtr LoadSampleFromFile(const std::wstring& fileName, const GS_SAMPLE_TYPE type = GSST_UNKNOWN);
	AudioSamplePtr LoadSampleFromFileInMemory(void *pBuffer, const unsigned int bufferLength, const GS_SAMPLE_TYPE type = GSST_UNKNOWN);

	void SetGlobalVolume(const float volume);
	float GetGlobalVolume() const;

	boost::any GetAudioContext();
};

typedef boost::shared_ptr<AudiereContext> AudiereContextPtr;

class AudiereSample : public AudioSample
{
	audiere::OutputStreamPtr m_output;
	int m_position;
	GS_SAMPLE_STATUS m_status;
	float m_volume;

	GS_SAMPLE_TYPE m_type;
	AudioWeakPtr m_audio;

	bool LoadSampleFromFile(AudioWeakPtr audio, const std::wstring& fileName, const GS_SAMPLE_TYPE type = GSST_UNKNOWN);
	bool LoadSampleFromFileInMemory(AudioWeakPtr audio, void *pBuffer, const unsigned int bufferLength, const GS_SAMPLE_TYPE type = GSST_UNKNOWN);

public:
	AudiereSample();
	~AudiereSample();

	bool SetLoop(const bool enable);
	bool GetLoop() const;

	bool Play();
	GS_SAMPLE_STATUS GetStatus();

	bool IsPlaying();

	bool Pause();
	bool Stop();

	GS_SAMPLE_TYPE GetType() const;

	bool SetSpeed(const float speed);
	float GetSpeed() const;

	bool SetVolume(const float volume);
	float GetVolume() const;

	bool SetPan(const float pan);
	float GetPan() const;
};

} // namespace gs2d

#endif