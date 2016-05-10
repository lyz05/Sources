{$M 8192,0,0}
uses dos;
begin
  SwapVectors;
  Exec(GetEnv('COMSPEC'), '/c ver');
  SwapVectors;
  readln;
end.