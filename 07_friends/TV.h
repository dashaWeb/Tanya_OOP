#pragma once
class TV
{
	bool state;
	size_t current_volume;
	size_t current_channel;
	size_t number_of_channel;
	size_t max_volume;
public:
	TV(const bool& state, const size_t& max_volume, const size_t& number_of_channel, const size_t& current_channel, const size_t& current_volume)
		:state(state), max_volume(max_volume), number_of_channel(number_of_channel), current_channel(current_channel), current_volume(current_volume){}
	TV() :TV(false, 50, 100, 1, 10) {}
	void power();
	void nextChannel();
	void prevChannel();
	void incVolume();
	void decVolume();
	void show() const;
};

