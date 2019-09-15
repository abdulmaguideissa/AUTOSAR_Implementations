/************************************************************
* Module:      Compiler abstraction.
* File Name:   Compiler.h
* Description: Abstraction from compiler specific keywords 
			   based on the AUTOSAR Compiler SWS.
* Author:      Abdulmaguid Eissa.
*************************************************************/

#ifndef COMPILER_H  
#define COMPILER_H 

/* Id for the company in the AUTOSAR */
#define PLATFORM_VENDOR_ID                          (2020U)

/* Compiler Module Id */
#define COMPILER_MODULE_ID                          (198U)

/* Module Version 1.0.0 */
#define COMPILER_SW_MAJOR_VERSION                   (1U)
#define COMPILER_SW_MINOR_VERSION                   (0U)
#define COMPILER_SW_PATCH_VERSION                   (0U)

/* AUTOSAR Version 4.3.1 */
#define COMPILER_AR_RELEASE_MAJOR_VERSION           (4U)
#define COMPILER_AR_RELEASE_MINOR_VERSION           (3U)
#define COMPILER_AR_RELEASE_PATCH_VERSION           (1U)


/* Memory class AUTOMATIC 
   Empty definition */
#define AUTOMATIC                          

/* Memory class TYPEDEF
   Empty definition */
#define TYPEDEF

/* Null Pointer */
#define NULL_PTR                     ((void *)0)

/* Inline */
#define INLINE                       inline

/* Local inline */
#define LOCAL_INLINE                 static inline

/* Local definition */
#define STATIC                       static

/***************************************************************
* Macro name:         FUNC
* Parameters (in):    retype  return type of the function 
					  memclass  classification of the function itself.
* Parameters (out):   None
* Return value:       None
* Description:        The compiler abstraction shall define the FUNC macro 
                      for the declaration and definition of functions that 
                      ensures correct syntax of function declarations as 
                      required by a specific compiler.
****************************************************************/
#define FUNC(rettype, memclass)      memclass rettype

/***************************************************************
* Macro name:         FUNC_P2CONST
* Parameters (in):    rettype  return type of the function 
					  ptrclass  defines the classification of the pointer’s distance
                      memclass  classification of the function itself
* Parameters (out):   None
* Return value:       None
* Description:        The compiler abstraction shall define the FUNC_P2CONST
                      macro for the declaration and definition of functions 
                      returning a pointer to a constant. This shall 
                      ensure the correct syntax of function declarations 
                      as required by a specific compiler. 
****************************************************************/
#define FUNC_P2CONST(rettype, ptrclass, memclass) \
		const ptrclass rettype * memclass

/***************************************************************
* Macro name:         FUNC_P2VAR
* Parameters (in):    rettype  return type of the function
                      ptrclass  defines the classification of the pointer’s distance
                      memclass  classification of the function itself
* Parameters (out):   None
* Return value:       None
* Description:        The compiler abstraction shall define the FUNC_P2VAR 
                      macro for the declaration and definition of 
                      functions returning a pointer to a variable. 
                      This shall ensure the correct syntax of function
                      declarations as required by a specific compiler.
****************************************************************/
#define FUNC_P2VAR(rettype, ptrclass, memclass) \
		ptrclass rettype * memclass


#endif /* COMPILER_H */