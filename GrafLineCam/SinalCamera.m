s = serial('COM8');
set(s,'Terminator','CR');
fopen(s);
while true
    while fgets(s)~='X'
    end
    dados = zeros(1,128);
    
    for cont = 1:128
     dados(cont) = str2double(fgets(s));
    end
    plot(dados,'-r','LineWidth',1.5)
    axis([0 128 0 max(dados)])
    hold on
    plot([1 128],[4000 4000])
    hold off
    pause(0.01);
end
fclose(s);
delete(s);
