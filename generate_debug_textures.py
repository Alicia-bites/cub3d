import os
import shutil
import traceback
import sys
from PIL import Image, ImageDraw, ImageFont
try:
	from xpm import pil_save
except:
	print("Error: xpm module not found. Please install it with 'pip install xpm'")
	exit(1)


size = 64
if len(sys.argv) > 1:
	size = int(sys.argv[1])
else:
	print("Using default size: 64")
	print("To set a custom size : generate_debug_textures.py <size>\n")

BG_COLOR = (247, 7, 243)
TXT_COLOR = (0, 0, 0)
TEXTURES = ["EA", "NO", "SO", "WE"]
FONT_FILE = "arial.ttf"

print("Creating debug textures with size: {}".format(size))
print("Background color: {}".format(BG_COLOR))
print("Text color: {}".format(TXT_COLOR))
print("Names : {}".format(TEXTURES))

def dump_texture(sq_size: int, text: str, output_path: str) -> None:
	"""
	Creates a debug texture of a given size and a centered text
	"""
	img = Image.new('RGB', (sq_size, sq_size), color = BG_COLOR)
	d = ImageDraw.Draw(img)
	font = ImageFont.truetype(FONT_FILE, int(sq_size / 2))
	d.fontmode = "1"
	d.text((sq_size/2, sq_size/2), text, fill=TXT_COLOR, anchor="mm", font=font)
	with open(output_path, "wb+") as f:
		xpm_data = pil_save(img, variable_name=text.lower().encode())
		xpm_data = xpm_data.replace(b"'\"", b"\"")
		xpm_data = xpm_data.replace(b"b'", b"")
		f.write(xpm_data)

print(f"Creating {size}x{size} textures..", end=" ", flush=True)
try:
	for texture in TEXTURES:
		dump_texture(size, texture, texture.lower() + ".xpm")
	print("✅")
except:
	# Uncomment L52 to debug in case of error
	# traceback.print_exc()
	print("❌")