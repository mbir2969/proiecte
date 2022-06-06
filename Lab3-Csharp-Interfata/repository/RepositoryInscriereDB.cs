using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Data;
using Lab3.model;
using log4net;
using tasks.repository;

namespace Lab3.repository
{

    public class RepositoryInscriereDB : Repository<int, Inscriere>
    {
        private static readonly ILog logger = LogManager.GetLogger(System.Reflection.MethodBase.GetCurrentMethod().DeclaringType);
        IDictionary<String, string> props;

        public RepositoryInscriereDB(IDictionary<string, string> props)
        {
            logger.Info("Initializing repository inscrieri task.");
            this.props = props;
        }

        public void add(Inscriere elem)
        {
            logger.InfoFormat("Saving task: {0}.", elem.ToString());
            var connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText =
                    "insert into Inscrieri (idParticipant, numeParticipant, varsta, numarProbe, idOrganizator, username, password, proba) values (@idParticipant, @numeParticipant, @varsta, @numarProbe, @idOrganizator, @username, @password, @proba)";
                var paramIdParticipnat = command.CreateParameter();
                paramIdParticipnat.ParameterName = "@idParticipant";
                paramIdParticipnat.Value = elem.getParticipant().getID();
                command.Parameters.Add(paramIdParticipnat);

                var paramNumeParticipant = command.CreateParameter();
                paramNumeParticipant.ParameterName = "@numeParticipant";
                paramNumeParticipant.Value = elem.getParticipant().getNume();
                command.Parameters.Add(paramNumeParticipant);

                var paramVarsta = command.CreateParameter();
                paramVarsta.ParameterName = "@varsta";
                paramVarsta.Value = elem.getParticipant().getVarsta().ToString();
                command.Parameters.Add(paramVarsta);

                var paramNumarProbe = command.CreateParameter();
                paramNumarProbe.ParameterName = "@numarProbe";
                paramNumarProbe.Value = elem.getParticipant().getNumarProbe();
                command.Parameters.Add(paramNumarProbe);

                var paramIdOrganizator = command.CreateParameter();
                paramIdOrganizator.ParameterName = "@idOrganizator";
                paramIdOrganizator.Value = elem.getOrganizator().getID();
                command.Parameters.Add(paramIdOrganizator);

                var paramUsername = command.CreateParameter();
                paramUsername.ParameterName = "@username";
                paramUsername.Value = elem.getOrganizator().getUserName();
                command.Parameters.Add(paramUsername);

                var paramPassword = command.CreateParameter();
                paramPassword.ParameterName = "@password";
                paramPassword.Value = elem.getOrganizator().getPassword();
                command.Parameters.Add(paramPassword);

                var paramProba = command.CreateParameter();
                paramProba.ParameterName = "@proba";
                paramProba.Value = elem.getProba().ToString();
                command.Parameters.Add(paramProba);

                var result = command.ExecuteNonQuery();
                logger.InfoFormat("Saved {0} instances.", result);   

            }
            logger.InfoFormat("Instance {0} was saved.", elem.ToString());
        }

        public void delete(int id)
        {
            logger.InfoFormat("Deleting task {0}.", id.ToString());
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "delete from Inscrieri where id=@id";
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);
                var result = command.ExecuteNonQuery();
                
                logger.InfoFormat("Deleted {0} instances.", result);
            }
            logger.InfoFormat("Instance with id {0} was deleted.", id.ToString());
        }

        public void update(Inscriere elem, int id)
        {
            logger.InfoFormat("Updating task {0}.", elem.ToString());
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText =
                    "update Inscrieri set idParticipant = @idParticipant, numeParticipant= @numeParticipant, varsta = @varsta, numarProbe = @numarProbe, idOrganizator = @idOrganizator, username = @username, password = @password, proba = @proba where id = @id";
                var paramIdParticipnat = command.CreateParameter();
                paramIdParticipnat.ParameterName = "@idParticipant";
                paramIdParticipnat.Value = elem.getParticipant().getID();
                command.Parameters.Add(paramIdParticipnat);

                var paramNumeParticipant = command.CreateParameter();
                paramNumeParticipant.ParameterName = "@numeParticipant";
                paramNumeParticipant.Value = elem.getParticipant().getNume();
                command.Parameters.Add(paramNumeParticipant);

                var paramVarsta = command.CreateParameter();
                paramVarsta.ParameterName = "@varsta";
                paramVarsta.Value = elem.getParticipant().getVarsta().ToString();
                command.Parameters.Add(paramVarsta);

                var paramNumarProbe = command.CreateParameter();
                paramNumarProbe.ParameterName = "@numarProbe";
                paramNumarProbe.Value = elem.getParticipant().getNumarProbe();
                command.Parameters.Add(paramNumarProbe);

                var paramIdOrganizator = command.CreateParameter();
                paramIdOrganizator.ParameterName = "@idOrganizator";
                paramIdOrganizator.Value = elem.getOrganizator().getID();
                command.Parameters.Add(paramIdOrganizator);

                var paramUsername = command.CreateParameter();
                paramUsername.ParameterName = "@username";
                paramUsername.Value = elem.getOrganizator().getUserName();
                command.Parameters.Add(paramUsername);

                var paramPassword = command.CreateParameter();
                paramPassword.ParameterName = "@password";
                paramPassword.Value = elem.getOrganizator().getPassword();
                command.Parameters.Add(paramPassword);

                var paramProba = command.CreateParameter();
                paramProba.ParameterName = "@proba";
                paramProba.Value = elem.getProba();
                command.Parameters.Add(paramProba);

                var paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);

                var result = command.ExecuteNonQuery();
                logger.InfoFormat("Updated {0} instances.", result);
            }
            logger.InfoFormat("Instance {0} was updated.", elem.ToString());
        }

        public Inscriere findById(int id)
        {
            logger.InfoFormat("Finding one task.");
            IDbConnection connection = DBUtils.getConnection(props);
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Inscrieri where id = @id";
                IDbDataParameter paramId = command.CreateParameter();
                paramId.ParameterName = "@id";
                paramId.Value = id;
                command.Parameters.Add(paramId);

                using (var result = command.ExecuteReader())
                {
                    if (result.Read())
                    {
                        int idParticpant = result.GetInt32(1);
                        String nume = result.GetString(2);
                        CategorieVarsta.TryParse(result.GetString(3), out CategorieVarsta varsta);
                        int numarProbe = result.GetInt32(4);
                        Participant participant = new Participant(nume, varsta, numarProbe);
                        participant.setID(idParticpant);
                        int idOrganizator = result.GetInt32(5);
                        String username = result.GetString(6);
                        String password = result.GetString(7);
                        Organizator organizator = new Organizator(username, password);
                        organizator.setID(idOrganizator);
                        Proba.TryParse(result.GetString(8), out Proba proba);
                        Inscriere inscriere = new Inscriere(organizator, participant, proba);
                        inscriere.setID(id);
                        logger.InfoFormat("Instance with id {0} was found", id.ToString());
                        return inscriere;
                    }
                }
            }
            logger.InfoFormat("No instance with id {0} was found.", id.ToString());
            return null;
        }

        public IEnumerable<Inscriere> findAll()
        {
            logger.InfoFormat("Finding all task.");
            IDbConnection connection = DBUtils.getConnection(props);
            IList<Inscriere> inscrieri = new List<Inscriere>();
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Inscrieri";

                using (var result = command.ExecuteReader())
                {
                    while (result.Read())
                    {
                        int id = result.GetInt32(0);
                        int idParticpant = result.GetInt32(1);
                        String nume = result.GetString(2);
                        CategorieVarsta.TryParse(result.GetString(3), out CategorieVarsta varsta);
                        int numarProbe = result.GetInt32(4);
                        Participant participant = new Participant(nume, varsta, numarProbe);
                        participant.setID(idParticpant);
                        int idOrganizator = result.GetInt32(5);
                        String username = result.GetString(6);
                        String password = result.GetString(7);
                        Organizator organizator = new Organizator(username, password);
                        organizator.setID(idOrganizator);
                        Proba.TryParse(result.GetString(8), out Proba proba);
                        Inscriere inscriere = new Inscriere(organizator, participant, proba);
                        inscriere.setID(id);
                        inscrieri.Add(inscriere);
                    }
                }
            }
            logger.InfoFormat("{0} instances found.", inscrieri.Count.ToString());
            return inscrieri;
        }

        public Collection<Inscriere> getAll()
        {
            logger.InfoFormat("Getting all task.");
            IDbConnection connection = DBUtils.getConnection(props);
            Collection<Inscriere> inscrieri = new Collection<Inscriere>();
            using (var command = connection.CreateCommand())
            {
                command.CommandText = "select * from Inscrieri";

                using (var result = command.ExecuteReader())
                {
                    while (result.Read())
                    {
                        int id = result.GetInt32(0);
                        int idParticpant = result.GetInt32(1);
                        String nume = result.GetString(2);
                        CategorieVarsta.TryParse(result.GetString(3), out CategorieVarsta varsta);
                        int numarProbe = result.GetInt32(4);
                        Participant participant = new Participant(nume, varsta, numarProbe);
                        participant.setID(idParticpant);
                        int idOrganizator = result.GetInt32(5);
                        String username = result.GetString(6);
                        String password = result.GetString(7);
                        Organizator organizator = new Organizator(username, password);
                        organizator.setID(idOrganizator);
                        Proba.TryParse(result.GetString(8), out Proba proba);
                        Inscriere inscriere = new Inscriere(organizator, participant, proba);
                        inscriere.setID(id);
                        inscrieri.Add(inscriere);
                    }
                }
            }
            logger.InfoFormat("{0} instances found.", inscrieri.Count.ToString());
            return inscrieri;
        }
    }
}