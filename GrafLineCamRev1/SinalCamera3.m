   s = serial('COM8');
set(s,'Terminator','CR');
fopen(s);
while true
    while fgets(s)~='X'
    end
    dados = zeros(1,128);
    linha= zeros(1,110);
    
    for cont = 1:128
     dados(cont) = str2double(fgets(s));
    end
    
    amostraMaior = 0;
	amostraMenor = 100000;
	for cont=18:128
		if amostraMaior<dados(cont)
			amostraMaior=dados(cont);
		end
		if amostraMenor>dados(cont)
			amostraMenor=dados(cont);
		end
	end
    
    for cont = 18:128
     linha(cont-17)=floor((10/(amostraMaior-amostraMenor))*(dados(cont-17)-amostraMenor));
    end
    
    plot(linha,'-r','LineWidth',1.5)
    axis([0 110 0 10])%max(linha)
    hold on
    %plot([1 128],[4000 4000])
    hold off
    pause(0.01);
end
fclose(s);
delete(s);
