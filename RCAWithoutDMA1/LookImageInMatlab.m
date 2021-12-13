s = serial('COM5');
set(s,'Terminator','CR');
fopen(s);

Px = 1;
Py = 1;
buf = 0;
dados = zeros(70,55);
buffer = zeros(1,3921);

buf = fgets(s);
while ~(buf(1)=='1' && buf(2)=='0' && buf(3)=='0' && buf(4)=='0')
    buf = fgets(s);
end
disp('START')
for i=1:3920
    buffer(i) = str2double(buf);
    buf = fgets(s);
end

Px = 1;
Py = 1;

for i=1:3920
   if buffer(i) == 1000
       Px = 1;
       Py = 1;
   elseif buffer(i) == 800
       Px = 1;
       Py = Py + 1;
   else
       dados(Py,Px) = uint8((255/100)*buffer(i)-35);
       Px=Px+1;
   end
end
Px = 1;
Py = 1;

imshow(mat2gray(dados))

fclose(s);
delete(s);