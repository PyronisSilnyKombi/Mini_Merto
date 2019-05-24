#include "cLocomotive.h"

cLocomotive::cLocomotive(double x, double y, char line_color, int capacity) :cPassengerStore(x, y, capacity), line_color_(line_color){

}

int cLocomotive::unload(cStation a) {
	/*int tmp_shape = a.shape();
	auto newEnd = std::remove_if(passengers_.begin(), passengers_.end(), [tmp_shape](auto) {
		if (tmp_shape == shape_) i = n;
		return --i == 0;
	});
	passengers_.erase(newEnd, passengers_.end());

	for (auto el : passengers_) {
		if (el == a.shape()) el.erase();
	}*/
	return 0;
}