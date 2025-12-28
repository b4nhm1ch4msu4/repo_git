-- Num = 42
--
-- S = "this is a string"
-- S2 = "this is a str too"
-- S3 = [[ this still a string
-- 	with multi
-- 	line]]
--
-- while Num < 50 do
-- 	Num = Num + 2
-- end
--
-- if Num > 50 then
-- 	print("Num is greater than 50")
-- elseif S ~= "this is a string" then
-- 	io.write("Num is smaller than 50")
-- else
-- 	local str = io.read()
-- 	print(str .. " was input from stdin")
-- end
--
-- foo = unknowvalue
-- print(foo)
--
--
-- Loops
-- for include both start value and end value
-- for i = 0, 5, 1 do
-- 	print("first loop: " .. i)
-- end
-- print("-------------------------")
--
-- for i = 5, 0, -1 do
-- 	io.write("second loop: " .. i .. "\n")
-- end
-- print("-------------------------")
--
-- for i = 0, 5 do
-- 	print("third loop: " .. i)
-- end
-- print("-------------------------")
--
-- local i = 0
-- repeat
-- 	io.write("fouth loop: " .. i .. "\n")
-- 	i = i - 1
-- until i < 0
-- print("-------------------------")
--
--
-- Functions
-- local f = function()
-- 	return 5
-- end
-- print(f())
--
--
-- Table data struct
--
-- T = { key1 = "first value", key2 = "second value" }
-- print(T.key1)
--
-- T["$"] = "third value"
-- print(T["$"])
--
-- local function h(x)
-- 	print(x.key2)
-- end
-- h({ key1 = "key1" })

-- local list = { "one", "two", "three", "four" }
--
-- for i = 1, #list do
-- 	print(list[i])
-- end

-- Metadata
-- __add(a, b)                     for a + b
-- __sub(a, b)                     for a - b
-- __mul(a, b)                     for a * b
-- __div(a, b)                     for a / b
-- __mod(a, b)                     for a % b
-- __pow(a, b)                     for a ^ b
-- __unm(a)                        for -a
-- __concat(a, b)                  for a .. b
-- __len(a)                        for #a
-- __eq(a, b)                      for a == b
-- __lt(a, b)                      for a < b
-- __le(a, b)                      for a <= b
-- __index(a, b)  <fn or a table>  for a.b
-- __newindex(a, b, c)             for a.b = c
-- __call(a, ...)                  for a(...)

f4 = { a = 1, b = 2 }
f5 = { a = 3, b = 4 }

-- metafraction = {}
-- function metafraction.__add(f1, f2)
-- 	sum = {}
-- 	sum.b = f1.b * f2.b
-- 	sum.a = f1.a * f2.b + f2.a * f1.b
-- 	return sum
-- end
-- setmetatable(f5, metafraction)
-- setmetatable(f4, metafraction)

setmetatable(f4, {
	__add = function(f1, f2)
		local f3 = {}
		f3.a = f1.a * f2.b + f2.a * f1.b
		f3.b = f1.b * f2.b
		return f3
	end,
})

setmetatable(f5, {
	__add = function(f1, f2)
		local f3 = {}
		f3.a = f1.a * f2.b + f2.a * f1.b
		f3.b = f1.b * f2.b
		return f3
	end,
})
--

local f3 = f4 + f5
print("fration f3: " .. f3.a .. "/" .. f3.b)

--#region Class-like table and inheritance
