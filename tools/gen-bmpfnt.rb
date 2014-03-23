#!/usr/bin/ruby
 
# Create .fnt file for fixed font.
 
font_image_file_name = ARGV.shift || 'font.png'
fontw = ARGV.shift || 8
fonth = ARGV.shift || 8
cols = ARGV.shift || 16
rows = ARGV.shift || 6
start = ARGV.shift || 32 # Space
 
puts <<EOD
info face="" size=0 bold=0 italic=0 charset="" unicode=0 stretchH=100 smooth=0 aa=1 padding=0,0,0,0 spacing=1,1
common lineHeight=#{fonth} base=0 scaleW=10 scaleH=100 pages=1 packed=0
page id=0 file="#{font_image_file_name}"
 
chars count=#{rows * cols}
EOD
 
rows.times do |i|
	cols.times do |j|
		c = start + i * cols + j
	 
		puts <<EOD
char id=#{c} x=#{j * fontw} y=#{i * fonth} width=#{fontw} height=#{fonth} xoffset=0 yoffset=0 xadvance=#{fontw} page=0 chnl=0 // #{c.chr}
EOD
	end
end
