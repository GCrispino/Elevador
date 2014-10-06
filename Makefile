.PHONY: clean All

All:
	@echo "----------Building project:[ Caixa_Eletronico - Debug ]----------"
	@cd "C:\Users\Crispino\Documents\ProgII\Caixa_Eletronico" && $(MAKE) -f  "Caixa_Eletronico.mk"
clean:
	@echo "----------Cleaning project:[ Caixa_Eletronico - Debug ]----------"
	@cd "C:\Users\Crispino\Documents\ProgII\Caixa_Eletronico" && $(MAKE) -f  "Caixa_Eletronico.mk" clean
