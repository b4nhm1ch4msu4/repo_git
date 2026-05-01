# class Influencer:
#     def __init__(self, num_selfies, num_bio_links):
#         self.num_selfies = num_selfies
#         self.num_bio_links = num_bio_links
#
#     def __repr__(self):
#         return f"({self.num_selfies}, {self.num_bio_links})"
#
#
# # dont touch above this line
#
#
# def vanity(influencer):
#     return influencer.num_bio_links * 5 + influencer.num_selfies
#
#
# def vanity_sort(influencers):
#     return sorted(influencers,key=vanity)


# def bubble_sort(nums):
#     swapping = True
#     end = len(nums)
#     while swapping:
#         swapping = False
#         for i in range(1, end):
#             if nums[i - 1] > nums[i]:
#                 temp = nums[i - 1]
#                 nums[i - 1] = nums[i]
#                 nums[i] = temp
#                 swapping = True
#         end -= 1
#     return nums


def merge_sort(nums):
    leng = len(nums)
    if leng < 2:
        return nums
    mid = leng // 2
    sorted_left_side = merge_sort(nums[:mid])
    sorted_right_side = merge_sort(nums[mid:])
    return merge(sorted_left_side, sorted_right_side)


def merge(first, second):
    pass


def insertion_sort(nums):
    if nums is None:
        return None
    leng = len(nums)
    for i in range(1, leng):
        j = i
        while j > 0 and nums[j - 1] > nums[j]:
            temp = nums[j]
            nums[j] = nums[j - 1]
            nums[j - 1] = temp
            j -= 1
    return nums


def quick_sort(nums, low, high):
    if low < high:
        middle = partition(nums, low, high)
        quick_sort(nums, low, middle - 1)
        quick_sort(nums, middle, high)


def partition(nums, low, high):
    pivot = nums[high]
    i = low - 1
    for j in range(low, high):
        if nums[j] < pivot:
            i += 1
            nums[i], nums[j] = nums[j], nums[i]
    nums[i + 1], nums[high] = nums[high], nums[i + 1]
    return i + 1

def selection_sort(nums):
    for i in range(len(nums)):
        smallest_idx = i
        for j in range(i+1,len(nums)):
            if nums[j] < nums[smallest_idx]:
                smallest_idx = j
        nums[i], nums[smallest_idx] = nums[smallest_idx], nums[i]
    return nums

def fib(n):
    if n <= 1:
        return n
    grandparent = 0
    parent = 1
    current = 0
    for i in range(n-1):
        current = parent + grandparent
        grandparent = parent
        parent = current
    return current


def letter_combinations(digits):
    if digits is None:
        return []
    result = ['']
    for d in digits:
        if d not in digit_to_letters:
            raise ValueError(f"invalid digit: {digits}")
        new_result = []
        letters = digit_to_letters[d]
        for combo in result:
            for letter in letters:
                new_result.append(combo + letter)
        result = new_result
    if result == ['']:
        return []
    return result
        


# Don't touch below this line

digit_to_letters = {
    "2": "abc",
    "3": "def",
    "4": "ghi",
    "5": "jkl",
    "6": "mno",
    "7": "pqrs",
    "8": "tuv",
    "9": "wxyz",
}



