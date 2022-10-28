#include<stdio.h>
#include<string.h>
/* Program to write 10 Product details to a file and write them into separate files based on the type (packed, fresh) of the product.
 Update stock when it reaches below or 5.

	Note: PNo, PName, Type, Quantity, CostperUnit as 	fields of a Product structure. */
struct product_details
{
    int pno;
    char pname[20];
    char type[20];
    int quantity;
    int costperunit;
};
typedef struct product_details product;


void copy(FILE *mainfile,FILE *copyfile){
    product p;
    while (!feof(copyfile))
    {
        fscanf(copyfile,"%d ",&p.pno);
        fscanf(copyfile,"%s ",&p.pname);
        fscanf(copyfile,"%s ",&p.type);
        fscanf(copyfile,"%d ",&p.quantity);
        fscanf(copyfile,"%d ",&p.costperunit);
        
        fprintf(mainfile,"%d ",p.pno);
        fprintf(mainfile,"%s ",p.pname);
        fprintf(mainfile,"%s ",p.type);
        fprintf(mainfile,"%d ",p.quantity);
        fprintf(mainfile,"%d ",p.costperunit);
        fprintf(mainfile,"%s","\n");
    }
    fclose(mainfile);
    fclose(copyfile);
    
}


void display(FILE *file){
    //file = fopen("product_details.txt","r");
    product p;
    
    int i = 1;
    while (!feof(file))
    {   
        fscanf(file,"%d ",&p.pno);
        printf("product %d no : %d\n",i,p.pno);
        fscanf(file,"%s ",&p.pname);
        printf("product %d name : %s\n",i,p.pname);
        fscanf(file,"%s ",&p.type);
        printf("product %d type : %s\n",i,p.type);
        fscanf(file,"%d ",&p.quantity);
        printf("product %d quantity: %d\n",i,p.quantity);
        fscanf(file,"%d ",&p.costperunit);
        printf("product %d costperunit : %d\n",i,p.costperunit);
        printf("=======================================\n");
       // fscanf(file,"%s",&tmp);
        i++;
    }
    fclose(file);
    
}
void buy(FILE *file){
    printf("enter product name: ");
    char prodname[20];
    scanf("%s",&prodname);
    printf("enter product quantity: ");
    int quant;
    scanf("%d",&quant);
    printf("enter product type[fresh/packed] : ");
    char type[20];
    scanf("%s",type);
    product p;
    FILE *tempfile;
    file = fopen("product_details.txt","r");
    tempfile = fopen("Tempprodfile.txt","w");
    while(!feof(file)){
        fscanf(file,"%d ",&p.pno);
        fscanf(file,"%s ",&p.pname);
        fscanf(file,"%s ",&p.type);
        fscanf(file,"%d ",&p.quantity);
        fscanf(file,"%d ",&p.costperunit);
        if((!strcmp(p.pname,prodname)) && (!strcmp(p.type,type))){
            if(p.quantity >= quant){
                if(p.quantity <= 5){
                    int quantity_now = p.quantity - quant;
                    printf("Update stock of product : %s\n",p.pname);
                    printf("%d product %s is bought\n",quant,p.pname);
                    p.quantity = quantity_now;
                }
                else{
                    int quatity_now = p.quantity - quant;
                    if (quatity_now <= 5 && quatity_now >= 0)
                    {
                        printf("Update stock of product : %s\n",p.pname);
                        int quantity_now = p.quantity - quant;
                        p.quantity = quantity_now;
                    }
                    else if(quatity_now < 0){
                        printf("Not enough stock of producct: %s\n",p.pname);
                    }
                    else{
                        int quantity_now = p.quantity - quant;
                        p.quantity = quantity_now;
                        printf("%d product %s is bought\n",quant,p.pname);
                    }
                }
            }
            else{
                printf("%d %s is not in stocks\n",quant,p.pname);
                return 0;
            }
        }
        else if((strcmp(p.type,type)) && (!strcmp(p.pname,prodname))){
            printf("%s product does not have %s type\n",p.pname,type);
        }
        fprintf(tempfile,"%d ",p.pno);
        fprintf(tempfile,"%s ",p.pname);
        fprintf(tempfile,"%s ",p.type);
        fprintf(tempfile,"%d ",p.quantity);
        fprintf(tempfile,"%d ",p.costperunit);
        fprintf(tempfile,"%s","\n");
    }
   // printf("There is no product names %s\n",prodname);
    fclose(file);
    fclose(tempfile);
    file = fopen("product_details.txt","w");
    tempfile = fopen("Tempprodfile.txt","r");
    copy(file,tempfile);
}

void main(){
    product p;
    FILE *file;
    file = fopen("product_details.txt","w");
    int n  = 1;
    for(int i = 0;i < 2;i++){
        printf("enter product %d no : ",n);
        scanf("%d",&p.pno);
        fprintf(file,"%d ",p.pno);
        printf("enter product %d pname : ",n);
        scanf("%s",&p.pname);
        fprintf(file,"%s ",p.pname);
        printf("enter product %d type[packed/fresh] : ",n);
        scanf("%s",&p.type);
        fprintf(file,"%s ",p.type);
        printf("enter product %d quantity : ",n);
        scanf("%d",&p.quantity);
        fprintf(file,"%d ",p.quantity);
        printf("enter product %d costperunit : ",n);
        scanf("%d",&p.costperunit);
        fprintf(file,"%d ",p.costperunit);
        fprintf(file,"%s","\n");
        n++;
    }
    fclose(file);
    FILE *freshfl,*packedfl;
    file = fopen("product_details.txt","r");
    freshfl = fopen("fresh_prod.txt","w");
    packedfl = fopen("packed_prod.txt","w");
    while(!feof(file)){
        fscanf(file,"%d ",&p.pno);
        fscanf(file,"%s ",&p.pname);
        fscanf(file,"%s ",&p.type);
        fscanf(file,"%d ",&p.quantity);
        fscanf(file,"%d ",&p.costperunit);
        if(!strcmp(p.type,"fresh")){
            fprintf(freshfl,"%d ",p.pno);
            fprintf(freshfl,"%s ",p.pname);
            fprintf(freshfl,"%s ",p.type);
            fprintf(freshfl,"%d ",p.quantity);
            fprintf(freshfl,"%d ",p.costperunit);
            fprintf(freshfl,"%s","\n");
        }
        else if(!strcmp(p.type,"packed")){
            fprintf(packedfl,"%d ",p.pno);
            fprintf(packedfl,"%s ",p.pname);
            fprintf(packedfl,"%s ",p.type);
            fprintf(packedfl,"%d ",p.quantity);
            fprintf(packedfl,"%d ",p.costperunit);
            fprintf(packedfl,"%s","\n");
            }      
    } 
    fclose(file);
    fclose(freshfl);
    fclose(packedfl);
    int choice;
    int fg = 1;
    while (fg)
    {
        printf("enter your choice : ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            file = fopen("product_details.txt","r");
            display(file);
            break;
        case 2:
            int tp;
            printf("enter 1:fresh product/2:packed product : ");
            scanf("%d",&tp);
            switch (tp)
            {
            case 1:
                freshfl = fopen("fresh_prod.txt","r");
                display(freshfl);                
                break;
            case 2:
                packedfl = fopen("packed_prod.txt","r");
                display(packedfl);
                break;
            
            default:
                break;
            }
            break;
        case 3:
            buy(file);
            break;
        case 4:
            fg = 0;
            break;
        default:
            break;
        }
    }
    
    display(file);

}

