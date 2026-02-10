function func(N)
  media = 0;
  maximo = N(1, 1);
  minimo = N(1,1);
  desvioPadrao = 0;

  for n = N,
    media = media + n;
    if n > maximo,
      maximo = n;
    endif
    if n < minimo,
      minimo = n;
    endif
  endfor
  media = media / columns(N);
  for n = N,
    desvioPadrao = desvioPadrao + (( n - media ).^2) / columns(N);

  endfor
   desvioPadrao = sqrt(desvioPadrao);
   desvioPadrao
   maximo
   minimo
   media
end
