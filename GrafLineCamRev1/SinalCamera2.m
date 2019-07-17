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
	
	amostraMaior = 0;
	amostraMenor = 100000;
	for cont=10:128
		if amostraMaior<dados(cont)
			amostraMaior=dados(cont);
		end
		if amostraMenor>dados(cont)
			amostraMenor=dados(cont);
		end
	end
	
	parteHist = (amostraMaior-amostraMenor)/10;
	histograma = zeros(1,10);
	for cont=10:128
		indice = floor((dados(cont)-amostraMenor)/parteHist);
		if (dados(cont)) ~= amostraMaior
			indice = indice + 1;
        end
        
        if ~isnan(indice)
            histograma(indice) = histograma(indice) + 1;
        end
	end

	index=0;
	menor=10000;
	for cont=1:10
		if histograma(cont) < menor  && histograma(cont)~=0
			menor = histograma(cont);
			index = cont;
		end
	end
	
    plot(dados,'-r','LineWidth',1.5)
    axis([0 128 0 max(dados)])
    hold on
	plot([1 128],[(parteHist*(index-1)+amostraMenor)+(0.5*parteHist) (parteHist*(index-1)+amostraMenor)+(0.5*parteHist)])
    hold off
    pause(0.01);
end
fclose(s);
delete(s);
