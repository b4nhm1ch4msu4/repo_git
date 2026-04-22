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
