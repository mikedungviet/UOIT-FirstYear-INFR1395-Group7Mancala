#include "Player.h"

/*
	This function performs a binary search to find a string
	@param arr[] The array to search in
	@param lastIndex The bigger side of Array
	@param value The value to search for
	@param firstIndex The smaller side of Array
	@return Return true if found
			Return false if not found
*/
bool Player::CheckValidMoves(std::string *arr, std::string value, int firstIndex, int lastIndex) {
	if (firstIndex <= lastIndex) {
		int midIndex = (firstIndex + lastIndex) / 2;

		if (value.compare(arr[midIndex])==0)
			return true;
		else if (arr[midIndex] > value)
			return CheckValidMoves(arr, value,0, midIndex - 1);
		else if (arr[midIndex] < value)
			return CheckValidMoves(arr, value, midIndex + 1);
	}
	return false;
}

