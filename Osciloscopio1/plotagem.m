s = serial('COM5');
set(s,'Terminator','CR');
fopen(s);
while true
    dados = zeros(1,128);
    while fgets(s)~='X'
    end
    
    for cont = 1:128
     dados(cont) = str2double(fgets(s));
    end
    
    maior = max(dados);
    menor = min(dados);
    
    limiar = ((maior - menor)/2)+ menor;
    
    plot(dados,'-r','LineWidth',1.5)
    hold on
    plot([0 128],[limiar limiar],'-b');
    plot([0 128],[limiar+25 limiar+25],'-g');
    hold off
    axis([0 128 0 255])
    pause(0.01);
end
fclose(s);
delete(s);