def binary_search_iterative(arr, target):
    """
    Binary search implementation using iterative approach.

    Args:
        arr: Sorted list of elements
        target: Element to search for

    Returns:
        int: Index of target if found, -1 otherwise

    Time Complexity: O(log n)
    Space Complexity: O(1)
    """
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = left + (right - left) // 2  # Prevents overflow

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1


def binary_search_recursive(arr, target, left=0, right=None):
    """
    Binary search implementation using recursive approach.

    Args:
        arr: Sorted list of elements
        target: Element to search for
        left: Left boundary (default: 0)
        right: Right boundary (default: len(arr) - 1)

    Returns:
        int: Index of target if found, -1 otherwise

    Time Complexity: O(log n)
    Space Complexity: O(log n) due to recursion stack
    """
    if right is None:
        right = len(arr) - 1

    if left > right:
        return -1

    mid = left + (right - left) // 2

    if arr[mid] == target:
        return mid
    elif arr[mid] < target:
        return binary_search_recursive(arr, target, mid + 1, right)
    else:
        return binary_search_recursive(arr, target, left, mid - 1)


def binary_search_leftmost(arr, target):
    """
    Find the leftmost (first) occurrence of target in a sorted array.

    Args:
        arr: Sorted list of elements (may contain duplicates)
        target: Element to search for

    Returns:
        int: Index of first occurrence if found, -1 otherwise
    """
    left, right = 0, len(arr) - 1
    result = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            result = mid
            right = mid - 1  # Continue searching left
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return result


def binary_search_rightmost(arr, target):
    """
    Find the rightmost (last) occurrence of target in a sorted array.

    Args:
        arr: Sorted list of elements (may contain duplicates)
        target: Element to search for

    Returns:
        int: Index of last occurrence if found, -1 otherwise
    """
    left, right = 0, len(arr) - 1
    result = -1

    while left <= right:
        mid = left + (right - left) // 2

        if arr[mid] == target:
            result = mid
            left = mid + 1  # Continue searching right
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return result


def binary_search_range(arr, target):
    """
    Find the range [start, end] of target in a sorted array.

    Args:
        arr: Sorted list of elements (may contain duplicates)
        target: Element to search for

    Returns:
        tuple: (start_index, end_index) if found, (-1, -1) otherwise
    """
    left = binary_search_leftmost(arr, target)
    if left == -1:
        return (-1, -1)

    right = binary_search_rightmost(arr, target)
    return (left, right)


# Example usage and test cases
if __name__ == "__main__":
    # Test array
    test_array = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
    test_array_with_duplicates = [1, 2, 2, 2, 3, 4, 4, 5, 6, 7]

    print("Binary Search Examples:")
    print("=" * 40)

    # Test iterative binary search
    print("Test Array:", test_array)
    target = 7
    result = binary_search_iterative(test_array, target)
    print(f"Iterative search for {target}: Index {result}")

    target = 6
    result = binary_search_iterative(test_array, target)
    print(f"Iterative search for {target}: Index {result} (not found)")

    # Test recursive binary search
    target = 15
    result = binary_search_recursive(test_array, target)
    print(f"Recursive search for {target}: Index {result}")

    print("\nDuplicate Handling Examples:")
    print("=" * 40)
    print("Test Array with Duplicates:", test_array_with_duplicates)

    # Test with duplicates
    target = 2
    leftmost = binary_search_leftmost(test_array_with_duplicates, target)
    rightmost = binary_search_rightmost(test_array_with_duplicates, target)
    range_result = binary_search_range(test_array_with_duplicates, target)

    print(f"Target {target}:")
    print(f"  Leftmost occurrence: Index {leftmost}")
    print(f"  Rightmost occurrence: Index {rightmost}")
    print(f"  Range: {range_result}")

    target = 4
    range_result = binary_search_range(test_array_with_duplicates, target)
    print(f"Target {target} range: {range_result}")

    # Performance comparison
    import time
    import random

    print("\nPerformance Test:")
    print("=" * 40)

    # Create large sorted array
    large_array = sorted([random.randint(1, 10000) for _ in range(10000)])
    target = large_array[len(large_array) // 2]  # Pick middle element

    # Test iterative
    start_time = time.time()
    for _ in range(1000):
        binary_search_iterative(large_array, target)
    iterative_time = time.time() - start_time

    # Test recursive
    start_time = time.time()
    for _ in range(1000):
        binary_search_recursive(large_array, target)
    recursive_time = time.time() - start_time

    print(f"Array size: {len(large_array)}")
    print(f"Iterations: 1000")
    print(f"Iterative approach: {iterative_time:.4f} seconds")
    print(f"Recursive approach: {recursive_time:.4f} seconds")
