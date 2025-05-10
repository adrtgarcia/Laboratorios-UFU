CREATE OR REPLACE FUNCTION atualizar_valortotal()
RETURNS TRIGGER AS $$
DECLARE
  valor_antigo NUMERIC := 0;
  valor_novo NUMERIC := 0;

BEGIN
  IF TG_OP = 'DELETE' OR TG_OP = 'UPDATE' THEN
    SELECT COALESCE(valunit, 0) INTO valor_antigo
    FROM produto
    WHERE codprod = OLD.codprod;
    
    valor_antigo := valor_antigo * OLD.quant;
  END IF;

  IF TG_OP = 'INSERT' OR TG_OP = 'UPDATE' THEN
    SELECT COALESCE(valunit, 0) INTO valor_novo
    FROM produto
    WHERE codprod = NEW.codprod;

    valor_novo := valor_novo * NEW.quant;
  END IF;

  UPDATE pedido
  SET valortotal = COALESCE(valortotal, 0) - valor_antigo + valor_novo
  WHERE numped = COALESCE(NEW.numped, OLD.numped);

  RETURN NULL;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trg_atualiza_valortotal
AFTER INSERT OR UPDATE OR DELETE ON itemped
FOR EACH ROW
EXECUTE FUNCTION atualizar_valortotal();
